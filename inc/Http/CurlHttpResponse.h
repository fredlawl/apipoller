#ifndef APIPOOLER_CURLHTTPRESPONSE_H
#define APIPOOLER_CURLHTTPRESPONSE_H

#include "HttpResponse.h"

namespace APIPOLLER {
    class CurlHttpResponse;
}

class APIPOLLER::CurlHttpResponse : public APIPOLLER::HttpResponse
{
public:
    static HttpResponse* createResponse();
    static HttpResponse* createResponseWithHttpInformation(const Http& httpInfo);
};

#endif
