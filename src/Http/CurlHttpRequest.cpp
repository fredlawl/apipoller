#include "../../inc/Http/CurlHttpRequest.h"

APIPOLLER::CurlHttpRequest::CurlHttpRequest()
{
    setUrl("");
    setMethod(Method::GET);
    open();
}


APIPOLLER::CurlHttpRequest::CurlHttpRequest(const String &url, Method method)
{
    setUrl(url);
    setMethod(method);
    open();
}


APIPOLLER::CurlHttpRequest::~CurlHttpRequest()
{
    close();
}


APIPOLLER::CurlHttpRequest *APIPOLLER::CurlHttpRequest::createCurlHttpRequestWithUrlAndMethod(const String &url, Method method)
{
    return new CurlHttpRequest(url, method);
}


APIPOLLER::CurlHttpRequest* APIPOLLER::CurlHttpRequest::createEmptyCurlHttpRequest()
{
    return new CurlHttpRequest();
}


bool APIPOLLER::CurlHttpRequest::sendSimpleRequest() const
{
    if (!curlHandle) {
        return false;
    }

    CURLcode curlResponseStatus = CURLE_OK;

    // ... do parameter encodings
    // ... fill-in headers
    // ... fill in request parameters

    return (curlResponseStatus == CURLE_OK);
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