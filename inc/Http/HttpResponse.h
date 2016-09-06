#ifndef APIPOLLER_HTTPRESPONSE_H
#define APIPOLLER_HTTPRESPONSE_H

#include "../APIPoller.h"

namespace APIPOLLER {
    class HttpRequest;
    class HttpResponse;
}

class APIPOLLER::HttpResponse
{
    friend class APIPOLLER::HttpRequest;

public:
    settings_t headers;
    String body;

    static HttpResponse* createResponse();

    HttpResponse() { };
    virtual ~HttpResponse() { }

    inline uint8_t getStatusCode() { return this->statusCode; }
    inline void setStatusCode(uint8_t code) { this->statusCode = code; }

    inline const String& getHttpVersion() { return this->httpVersion; }
    inline void setHttpVersion(const String& version) { this->httpVersion = version; }

    inline const String& getStatusMessage() { return this->statusMessage; }
    inline void setStatusMessage(const String& statusMessage) { this->statusMessage = statusMessage; }

protected:
    uint8_t statusCode = 0;
    String httpVersion = "";
    String statusMessage = "";

};

#endif