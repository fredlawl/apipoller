#ifndef APIPOLLER_HTTPRESPONSE_H
#define APIPOLLER_HTTPRESPONSE_H

#include "../APIPoller.h"

namespace APIPOLLER {
    class HttpResponse;
}

class APIPOLLER::HttpResponse
{
public:
    settings_t headers;
    String body;

    static HttpResponse* createResponse();
    static HttpResponse* createResponseWithHttpInformation(const String& httpVersion, uint8_t statusCode, const String& statusMessage);

    HttpResponse() { };
    virtual ~HttpResponse() { }

    inline uint8_t getStatusCode() { return this->statusCode; }
    inline const String& getHttpVersion() { return this->httpVersion; }
    inline const String& getStatusMessage() { return this->statusMessage; }

    void setHttpInformation(const String& httpVersion, uint8_t statusCode, const String& statusMessage);

protected:
    uint8_t statusCode = 0;
    String httpVersion = "";
    String statusMessage = "";

};

#endif