#include "../../inc/Http/HttpResponse.h"


APIPOLLER::HttpResponse *APIPOLLER::HttpResponse::createResponse()
{
    return new HttpResponse();
}



