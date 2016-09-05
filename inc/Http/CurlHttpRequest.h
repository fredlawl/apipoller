#ifndef APIPOLLER_CURLHTTPREQUEST_H
#define APIPOLLER_CURLHTTPREQUEST_H

#include "HttpRequest.h"

namespace APIPOLLER {
    class CurlHttpRequest;
    class IStreamReader;
}

class APIPOLLER::CurlHttpRequest : public APIPOLLER::HttpRequest
{
public:

    ~CurlHttpRequest();

    static CurlHttpRequest* createCurlHttpRequestWithUrlAndMethod(const String& url, APIPOLLER::HttpRequest::Method method);
    static CurlHttpRequest* createCurlHttpRequestWithStreamReader(IStreamReader* streamReader);
    static CurlHttpRequest* createEmptyCurlHttpRequest();

    bool sendSimpleRequest() const;

protected:
    void open();
    void close();

private:
    CURL* curlHandle = nullptr;
    IStreamReader* streamReader = nullptr;

    CurlHttpRequest();
    CurlHttpRequest(const String& url, Method method);
    CurlHttpRequest(IStreamReader* streamReader);

};

#endif
