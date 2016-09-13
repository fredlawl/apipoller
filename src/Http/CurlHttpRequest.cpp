#include "Http/CurlHttpRequest.h"
#include "Http/CurlHttpResponse.h"


APIPOLLER::CurlHttpRequest::~CurlHttpRequest()
{
    close();
}


APIPOLLER::CurlHttpRequest* APIPOLLER::CurlHttpRequest::createCurlHttpRequest(IEncoder* encoder)
{
    return new CurlHttpRequest(encoder);
}


APIPOLLER::CurlHttpRequest* APIPOLLER::CurlHttpRequest::createCurlHttpRequestWithStreamReader(IStreamReader* streamReader)
{
    return new CurlHttpRequest(streamReader);
}


APIPOLLER::CurlHttpRequest* APIPOLLER::CurlHttpRequest::createCurlHttpRequestWithEncoderAndStreamReader(IEncoder* encoder, IStreamReader* streamReader)
{
    return new CurlHttpRequest(encoder, streamReader);
}


APIPOLLER::HttpResponse *APIPOLLER::CurlHttpRequest::sendHeadersRequest(Method method, const String &url)
{
    writeBody = false;
    curl_easy_setopt(curlHandle, CURLOPT_NOBODY, 1L);
    return sendRequest(method, url);
}


APIPOLLER::HttpResponse* APIPOLLER::CurlHttpRequest::sendPostRequest(const String& url)
{
    if (!isCurlInitiated()) {
        return nullptr;
    }

    const char* queryString = buildQueryString().c_str();
    curl_easy_setopt(curlHandle, CURLOPT_POSTFIELDSIZE, ((long) strlen(queryString)));
    curl_easy_setopt(curlHandle, CURLOPT_COPYPOSTFIELDS, queryString);

    return sendRequest(Method::POST, url);
}


APIPOLLER::HttpResponse* APIPOLLER::CurlHttpRequest::sendGetRequest(const String& url)
{
    return sendRequest(Method::GET, url);
}


APIPOLLER::HttpResponse* APIPOLLER::CurlHttpRequest::sendPutRequest(const String& url)
{
    return sendRequest(Method::PUT, url);
}


APIPOLLER::HttpResponse* APIPOLLER::CurlHttpRequest::sendDeleteRequest(const String& url)
{
    return sendRequest(Method::DELETE, url);
}


APIPOLLER::HttpResponse* APIPOLLER::CurlHttpRequest::sendRequest(Method method, const String& url)
{
    if (!isCurlInitiated()) {
        return nullptr;
    }

    HttpResponse* response = CurlHttpResponse::createResponse();
    CURLcode curlResponseStatus = CURLE_OK;
    Http httpResponseInformation;
    String cleanedUrl = cleanUrl(url);
    String queryString = buildQueryString();

    if (method != Method::POST && !queryString.empty()) {
        cleanedUrl.append("?", 1).append(queryString);
    }

    curl_easy_setopt(curlHandle, CURLOPT_URL, cleanedUrl.c_str());
    curl_easy_setopt(curlHandle, CURLOPT_FOLLOWLOCATION, true);
    curl_easy_setopt(curlHandle, CURLOPT_NOPROGRESS, 1L);
    setCurlMethod(method);
    setResponseHeaderWriter(response);
    setResponseBodyWriter(response);
    setRequestHeaders();

    // ... do parameter encodings
    // ... fill-in headers
    // ... fill in request parameters
    curlResponseStatus = curl_easy_perform(curlHandle);
    if (curlResponseStatus != CURLE_OK) {
        std::cerr << "Request failed with message: " << curl_easy_strerror(curlResponseStatus) << std::endl;
        return nullptr;
    }

    curl_easy_getinfo(curlHandle, CURLINFO_RESPONSE_CODE, &httpResponseInformation.statusCode);

    // todo: Figure out a way to get the Http info
    response->setHttpInformation(httpResponseInformation);

    return response;
}


void APIPOLLER::CurlHttpRequest::open()
{
    curlHandle = curl_easy_init();
}


void APIPOLLER::CurlHttpRequest::close()
{
    if (!isCurlInitiated())
        return;

    curl_easy_cleanup(curlHandle);
}


void APIPOLLER::CurlHttpRequest::setResponseHeaderWriter(HttpResponse* response) const
{
    curl_easy_setopt(curlHandle, CURLOPT_HEADERFUNCTION, CurlHandler::writeToSettings);
    curl_easy_setopt(curlHandle, CURLOPT_HEADERDATA, &response->headers);
}


void APIPOLLER::CurlHttpRequest::setResponseBodyWriter(HttpResponse* response)
{
    if (!allowWriteBody()) {
        setResponseToNothing();
        return;
    }

    if (hasStreamReader()) {
        setResponseStreamWriter(response);
        return;
    }

    curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, CurlHandler::writeToString);
    curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &response->body);
}


void APIPOLLER::CurlHttpRequest::setResponseStreamWriter(HttpResponse* response) const
{
    curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, CurlHandler::writeToStreamReader);
    curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, streamReader);
}


void APIPOLLER::CurlHttpRequest::setResponseToNothing() const
{
    curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, CurlHandler::writeToNothing);
}


void APIPOLLER::CurlHttpRequest::setCurlMethod(Method method) const
{
    switch (method) {
        case Method::GET:
            curl_easy_setopt(curlHandle, CURLOPT_HTTPGET, 1L);
            break;
        case Method::POST:
            curl_easy_setopt(curlHandle, CURLOPT_POST, 1);
            break;
        case Method::DELETE:
            curl_easy_setopt(curlHandle, CURLOPT_CUSTOMREQUEST, "DELETE");
        case Method::PUT:
            curl_easy_setopt(curlHandle, CURLOPT_CUSTOMREQUEST, "PUT");
            break;
    }
}

bool APIPOLLER::CurlHttpRequest::allowWriteBody()
{
    if (!writeBody) {
        writeBody = true;
        return false;
    }

    return true;
}


void APIPOLLER::CurlHttpRequest::setRequestHeaders() const
{
    if (headers.isEmpty()) {
        return;
    }

    string_array_t headerKeys = headers.getHeaderKeys();
    struct curl_slist* curlHeaders = nullptr;
    String header;

    for (size_t i = 0; i < headerKeys.size(); ++i) {
        header = headers.getFormattedHeader(headerKeys[i]);
        curlHeaders = curl_slist_append(curlHeaders, header.c_str());
    }

    curl_easy_setopt(curlHandle, CURLOPT_HTTPHEADER, curlHeaders);
}


APIPOLLER::String APIPOLLER::CurlHttpRequest::cleanUrl(const String& url) const {
    String cleanedUrl = url;
    unsigned long found = cleanedUrl.find_first_of("?");

    if (found == cleanedUrl.npos)
        return cleanedUrl;

    return cleanedUrl.erase(found, cleanedUrl.npos);
}