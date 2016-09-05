#include "../../inc/Http/CurlHttpRequest.h"

APIPOLLER::CurlHttpRequest::CurlHttpRequest()
{
    setUrl("");
    open();
}


APIPOLLER::CurlHttpRequest::CurlHttpRequest(IStreamReader* streamReader)
{
    setUrl("");
    setMethod(Method::GET);
    open();
    this->streamReader = streamReader;
}


APIPOLLER::CurlHttpRequest::~CurlHttpRequest()
{
    close();
}


APIPOLLER::CurlHttpRequest *APIPOLLER::CurlHttpRequest::createCurlHttpRequestWithUrl(const String &url)
{
    return new CurlHttpRequest(url);
}


APIPOLLER::CurlHttpRequest *APIPOLLER::CurlHttpRequest::createCurlHttpRequestWithStreamReader(IStreamReader *streamReader)
{
    return new CurlHttpRequest(streamReader);
}


APIPOLLER::CurlHttpRequest* APIPOLLER::CurlHttpRequest::createEmptyCurlHttpRequest()
{
    return new CurlHttpRequest();
}


APIPOLLER::HttpResponse* APIPOLLER::CurlHttpRequest::sendPostRequest() const
{
    return sendRequest(Method::POST);
}


APIPOLLER::HttpResponse* APIPOLLER::CurlHttpRequest::sendGetRequest() const
{
    return sendRequest(Method::GET);
}


APIPOLLER::HttpResponse* APIPOLLER::CurlHttpRequest::sendPutRequest() const
{
    return sendRequest(Method::PUT);
}


APIPOLLER::HttpResponse* APIPOLLER::CurlHttpRequest::sendDeleteRequest() const
{
    return sendRequest(Method::DELETE);
}


APIPOLLER::HttpResponse* APIPOLLER::CurlHttpRequest::sendRequest(Method method) const
{
    if (!curlHandle) {
        return nullptr;
    }

    CURLcode curlResponseStatus = CURLE_OK;

    // ... do parameter encodings
    // ... fill-in headers
    // ... fill in request parameters

//    return (curlResponseStatus == CURLE_OK);

    return nullptr;
}


void APIPOLLER::CurlHttpRequest::open()
{
    curlHandle = curl_easy_init();
}


void APIPOLLER::CurlHttpRequest::close()
{
    if (!curlHandle)
        return;

    curl_easy_cleanup(curlHandle);
}