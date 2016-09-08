#include "../../inc/Http/HttpResponse.h"


APIPOLLER::HttpResponse *APIPOLLER::HttpResponse::createResponse()
{
    return new HttpResponse();
}


APIPOLLER::HttpResponse *APIPOLLER::HttpResponse::createResponseWithHttpInformation(const HTTP& httpInfo)
{
    HttpResponse* responseWithHttpInformation = createResponse();
    responseWithHttpInformation->setHttpInformation(httpInfo);
    return responseWithHttpInformation;
}


void APIPOLLER::HttpResponse::setHttpInformation(const HTTP& httpInfo)
{
    this->httpInfo = httpInfo;
}