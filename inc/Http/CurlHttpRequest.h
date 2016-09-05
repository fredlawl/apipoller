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
    static CurlHttpRequest* createCurlHttpRequestWithUrl(const String& url);
    static CurlHttpRequest* createCurlHttpRequestWithStreamReader(IStreamReader* streamReader);
    static CurlHttpRequest* createEmptyCurlHttpRequest();

    CurlHttpRequest();
    CurlHttpRequest(const String& url) : HttpRequest(url) { }
    CurlHttpRequest(IStreamReader* streamReader);

    ~CurlHttpRequest();

    HttpResponse* sendPostRequest() const;
    HttpResponse* sendGetRequest() const;
    HttpResponse* sendPutRequest() const;
    HttpResponse* sendDeleteRequest() const;
    HttpResponse* sendRequest(Method method) const;

protected:
    void open();
    void close();

private:
    CURL* curlHandle = nullptr;
    IStreamReader* streamReader = nullptr;

};

#endif
