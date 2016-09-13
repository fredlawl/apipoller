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
    static CurlHttpRequest* createCurlHttpRequest(IEncoder* encoder);
    static CurlHttpRequest* createCurlHttpRequestWithStreamReader(IStreamReader* streamReader);
    static CurlHttpRequest* createCurlHttpRequestWithEncoderAndStreamReader(IEncoder* encoder, IStreamReader* streamReader);

    CurlHttpRequest()
    {
        open();
    }

    CurlHttpRequest(IStreamReader* streamReader) : streamReader(streamReader)
    {
        open();
    }

    CurlHttpRequest(IEncoder* encoder) : HttpRequest(encoder)
    {
        open();
    }

    CurlHttpRequest(IEncoder* encoder, IStreamReader* streamReader) : HttpRequest(encoder), streamReader(streamReader)
    {
        open();
    }

    ~CurlHttpRequest();

    HttpResponse* sendHeadersRequest(Method method, const String& url);
    HttpResponse* sendPostRequest(const String& url);
    HttpResponse* sendGetRequest(const String& url);
    HttpResponse* sendPutRequest(const String& url);
    HttpResponse* sendDeleteRequest(const String& url);
    HttpResponse* sendRequest(Method method, const String& url);

    inline bool isCurlInitiated() const { return (curlHandle != nullptr); }
    inline bool hasStreamReader() const { return (streamReader != nullptr); }

protected:
    void open();
    void close();

private:
    CURL* curlHandle = nullptr;
    IStreamReader* streamReader = nullptr;
    bool writeBody = true;

    inline bool toggleWriteBody();
    void setCurlMethod(Method method) const;
    void setResponseHeaderWriter(HttpResponse* response) const;
    void setResponseBodyWriter(HttpResponse* response);
    void setResponseStreamWriter(HttpResponse* response) const;
    void setResponseToNothing() const;
    void setRequestHeaders() const;

    /**
     * Assuming a perfectly valid url, trim all the query params.
     */
    String cleanUrl(const String& url) const;

};

#endif
