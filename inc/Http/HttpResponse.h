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

    HttpResponse() { };
    virtual ~HttpResponse() { }

private:

};

#endif