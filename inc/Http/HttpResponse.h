#ifndef APIPOLLER_HTTPRESPONSE_H
#define APIPOLLER_HTTPRESPONSE_H

#include "Http.h"
#include "HttpHeaders.h"

namespace APIPOLLER {
    class HttpResponse;
}

class APIPOLLER::HttpResponse
{
public:
    HttpHeaders headers;
    String body;

    static HttpResponse* createResponse();
    static HttpResponse* createResponseWithHttpInformation(const Http& httpInfo);

    HttpResponse() { };
    virtual ~HttpResponse() { }

    inline long getStatusCode() { return this->httpInfo.statusCode; }
    inline const String& getHttpVersion() { return this->httpInfo.version; }
    inline const String& getStatusMessage() { return this->httpInfo.message; }

    void setHttpInformation(const Http& httpInfo);

protected:
    Http httpInfo;

};

#endif