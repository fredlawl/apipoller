#include "../../inc/Http/HttpResponse.h"


APIPOLLER::HttpResponse *APIPOLLER::HttpResponse::createResponse()
{
    return new HttpResponse();
}


APIPOLLER::HttpResponse *APIPOLLER::HttpResponse::createResponseWithHttpInformation(const String& httpVersion, long statusCode, const String& statusMessage)
{
    HttpResponse* responseWithHttpInformation = createResponse();
    responseWithHttpInformation->setHttpInformation(httpVersion, statusCode, statusMessage);
    return responseWithHttpInformation;
}


void APIPOLLER::HttpResponse::setHttpInformation(const String& httpVersion, long statusCode, const String& statusMessage)
{
    this->statusCode = statusCode;
    this->httpVersion = httpVersion;
    this->statusMessage = statusMessage;
}