#ifndef APIPOLLER_CURLHTTPREQUEST_H
#define APIPOLLER_CURLHTTPREQUEST_H

#include "../APIPoller.h"
#include "HttpRequest.h"

namespace APIPOLLER {
    class CurlHttpRequest;
}

class APIPOLLER::CurlHttpRequest : public APIPOLLER::HttpRequest
{
public:

    ~CurlHttpRequest();

    static CurlHttpRequest* createCurlHttpRequestWithUrlAndMethod(const String& url, Method method);
    static CurlHttpRequest* createEmptyCurlHttpRequest();

    bool sendSimpleRequest() const;

protected:
    void open();
    void close();

private:
    CURL* curlHandle = nullptr;

    CurlHttpRequest();
    CurlHttpRequest(const String& url, Method method);

};

#endif
