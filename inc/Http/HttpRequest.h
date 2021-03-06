#ifndef APIPOLLER_HTTPREQUEST_H
#define APIPOLLER_HTTPREQUEST_H

#include "Http.h"
#include "HttpHeaders.h"

namespace APIPOLLER {
    class HttpRequest;
    class IEncoder;
    class HttpResponse;
}

class APIPOLLER::HttpRequest
{
public:
    enum class Method : uint8_t {
        GET,
        POST,
        PUT,
        DELETE
    };

    settings_t parameters;
    HttpHeaders headers;

    virtual ~HttpRequest() {};

    virtual HttpResponse* sendHeadersRequest(Method method, const String& url) = 0;
    virtual HttpResponse* sendPostRequest(const String& url) = 0;
    virtual HttpResponse* sendGetRequest(const String& url) = 0;
    virtual HttpResponse* sendPutRequest(const String& url) = 0;
    virtual HttpResponse* sendDeleteRequest(const String& url) = 0;
    virtual HttpResponse* sendRequest(Method method, const String& url) = 0;

    inline void setEncoder(IEncoder* encoder) { this->encoder = encoder; };
    inline bool hasEncoder() const { return (encoder != nullptr); };

    /**
     * HttpRequest.cpp
     * Purpose: Encodes both key and value for query/post parameters.
     *
     * @return settings_t*|nullptr; nullptr on empty parameters or undefined encoder.
     */
    virtual settings_t* encodeParameters() const;

    virtual String buildQueryString() const;

protected:
    IEncoder* encoder = nullptr;

    HttpRequest() {};
    HttpRequest(IEncoder* encoder) {};

    /**
     * Call to open a connection request resource.
     */
    virtual void open() = 0;

    /**
     * Call to close and clean up any residual connection request resources.
     */
    virtual void close() = 0;

};

#endif
