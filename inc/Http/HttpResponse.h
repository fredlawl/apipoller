#ifndef APIPOLLER_HTTPRESPONSE_H
#define APIPOLLER_HTTPRESPONSE_H

#include "../APIPoller.h"

namespace APIPOLLER {
    class HttpResponse;
}

class APIPOLLER::HttpResponse
{
public:
    static HttpResponse* createResponseFromHeaders(const settings_t& headers);
    static HttpResponse* createEmptyResponse();

    HttpResponse() { };
    HttpResponse(const settings_t& headers) { this->headers = headers; }
    virtual ~HttpResponse() { }

private:
    settings_t headers;
};

#endif