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

    virtual ~HttpResponse() { }

protected:
    HttpResponse() { };
    HttpResponse(const settings_t& headers) { this->headers = headers; }

private:
    settings_t headers;
};

#endif