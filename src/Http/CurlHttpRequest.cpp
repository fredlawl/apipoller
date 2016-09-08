#include "../../inc/Http/CurlHttpRequest.h"
#include "../../inc/Http/HttpResponse.h"

APIPOLLER::CurlHttpRequest::CurlHttpRequest()
{
    open();
}


APIPOLLER::CurlHttpRequest::CurlHttpRequest(IStreamReader* streamReader)
{
    this->streamReader = streamReader;
    open();
}


APIPOLLER::CurlHttpRequest::~CurlHttpRequest()
{
    close();
}


APIPOLLER::CurlHttpRequest *APIPOLLER::CurlHttpRequest::createCurlHttpRequestWithStreamReader(IStreamReader *streamReader)
{
    return new CurlHttpRequest(streamReader);
}


APIPOLLER::CurlHttpRequest* APIPOLLER::CurlHttpRequest::createCurlHttpRequest()
{
    return new CurlHttpRequest();
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
    curl_easy_setopt(curlHandle, CURLOPT_POSTFIELDS, queryString);

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

    HttpResponse* response = HttpResponse::createResponse();
    CURLcode curlResponseStatus = CURLE_OK;

    curl_easy_setopt(curlHandle, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curlHandle, CURLOPT_FOLLOWLOCATION, true);
    curl_easy_setopt(curlHandle, CURLOPT_NOPROGRESS, 1L);
    setCurlMethod(method);
    setResponseHeaderWriter(response);
    setResponseBodyWriter(response);

    // ... do parameter encodings
    // ... fill-in headers
    // ... fill in request parameters
    curlResponseStatus = curl_easy_perform(curlHandle);
    if (curlResponseStatus != CURLE_OK) {
        std::cerr << "Request failed with message: " << curl_easy_strerror(curlResponseStatus) << std::endl;
    }

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

