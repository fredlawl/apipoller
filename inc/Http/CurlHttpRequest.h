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
    static CurlHttpRequest* createCurlHttpRequestWithStreamReader(IStreamReader* streamReader);
    static CurlHttpRequest* createCurlHttpRequest();

    CurlHttpRequest();
    CurlHttpRequest(IStreamReader* streamReader);

    ~CurlHttpRequest();

    HttpResponse* sendPostRequest(const String& url) const;
    HttpResponse* sendGetRequest(const String& url) const;
    HttpResponse* sendPutRequest(const String& url) const;
    HttpResponse* sendDeleteRequest(const String& url) const;
    HttpResponse* sendRequest(Method method, const String& url) const;

    inline bool isCurlInitiated() const { return (curlHandle != nullptr); }
    inline bool hasStreamReader() const { return (streamReader != nullptr); }

protected:
    void open();
    void close();

private:
    CURL* curlHandle = nullptr;
    IStreamReader* streamReader = nullptr;

    void setCurlMethod(Method method) const;
    void setResponseHeaderWriter(HttpResponse* response) const;
    void setResponseBodyWriter(HttpResponse* response) const;
    void setResponseStreamWriter(HttpResponse* response) const;

};

#endif
