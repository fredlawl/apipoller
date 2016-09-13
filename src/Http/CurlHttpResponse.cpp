#include "Http/CurlHttpResponse.h"

APIPOLLER::HttpResponse* APIPOLLER::CurlHttpResponse::createResponse()
{
    return new CurlHttpResponse();
}


APIPOLLER::HttpResponse* APIPOLLER::CurlHttpResponse::createResponseWithHttpInformation(const Http& httpInfo)
{
    HttpResponse* responseWithHttpInformation = createResponse();
    responseWithHttpInformation->setHttpInformation(httpInfo);
    return responseWithHttpInformation;
}