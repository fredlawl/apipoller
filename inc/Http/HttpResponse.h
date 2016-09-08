#ifndef APIPOLLER_HTTPRESPONSE_H
#define APIPOLLER_HTTPRESPONSE_H

#include "HTTP.h"

namespace APIPOLLER {
    class HttpResponse;
}

class APIPOLLER::HttpResponse
{
public:
    settings_t headers;
    String body;

    static HttpResponse* createResponse();
    static HttpResponse* createResponseWithHttpInformation(const HTTP& httpInfo);

    HttpResponse() { };
    virtual ~HttpResponse() { }

    inline long getStatusCode() { return this->httpInfo.statusCode; }
    inline const String& getHttpVersion() { return this->httpInfo.version; }
    inline const String& getStatusMessage() { return this->httpInfo.message; }

    void setHttpInformation(const HTTP& httpInfo);

protected:
    HTTP httpInfo;

};

#endif