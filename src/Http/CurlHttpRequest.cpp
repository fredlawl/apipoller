#include "../../inc/Http/CurlHttpRequest.h"

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


APIPOLLER::HttpResponse* APIPOLLER::CurlHttpRequest::sendPostRequest(const String& url) const
{
    return sendRequest(Method::POST, url);
}


APIPOLLER::HttpResponse* APIPOLLER::CurlHttpRequest::sendGetRequest(const String& url) const
{
    return sendRequest(Method::GET, url);
}


APIPOLLER::HttpResponse* APIPOLLER::CurlHttpRequest::sendPutRequest(const String& url) const
{
    return sendRequest(Method::PUT, url);
}


APIPOLLER::HttpResponse* APIPOLLER::CurlHttpRequest::sendDeleteRequest(const String& url) const
{
    return sendRequest(Method::DELETE, url);
}


APIPOLLER::HttpResponse* APIPOLLER::CurlHttpRequest::sendRequest(Method method, const String& url) const
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