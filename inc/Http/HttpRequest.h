#ifndef APIPOLLER_HTTPREQUEST_H
#define APIPOLLER_HTTPREQUEST_H

#include "../Encoders/IEncoder.h"

namespace APIPOLLER {
    class HttpRequest;
}

class APIPOLLER::HttpRequest
{
public:
    enum class Method {
        GET,
        POST,
        PUT,
        DELETE
    };

    settings_t parameters;
    settings_t headers;

    virtual ~HttpRequest() {};
    virtual bool sendSimpleRequest() const = 0;

    void setEncoder(IEncoder* encoder) { this->encoder = encoder; };

    inline Method getMethod() const { return method; };
    inline void setMethod(Method method) { this->method = method; };

    inline String getUrl() const { return url; }
    inline void setUrl(const String& url) { this->url = url; }

    /**
     * HttpRequest.cpp
     * Purpose: Encodes both key and value for query/post parameters.
     *
     * @return settings_t*|nullptr; nullptr on empty parameters or undefined encoder.
     */
    virtual settings_t* encodeParameters() const;

protected:
    String url;
    Method method;
    IEncoder* encoder = nullptr;

    HttpRequest() {};

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
