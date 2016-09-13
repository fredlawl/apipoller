#ifndef APIPOOLER_HTTPREQUESTMOCK_H
#define APIPOOLER_HTTPREQUESTMOCK_H

#include "gmock/gmock.h"
#include "Http/HttpRequest.h"
#include "Http/HttpResponse.h"

class HttpRequestMock : public APIPOLLER::HttpRequest
{
public:
    HttpRequestMock() {}
    MOCK_METHOD2(sendHeadersRequest, APIPOLLER::HttpResponse*(APIPOLLER::HttpRequest::Method method, const APIPOLLER::String& url));
    MOCK_METHOD1(sendPostRequest, APIPOLLER::HttpResponse*(const APIPOLLER::String& url));
    MOCK_METHOD1(sendGetRequest, APIPOLLER::HttpResponse*(const APIPOLLER::String& url));
    MOCK_METHOD1(sendPutRequest, APIPOLLER::HttpResponse*(const APIPOLLER::String& url));
    MOCK_METHOD1(sendDeleteRequest, APIPOLLER::HttpResponse*(const APIPOLLER::String& url));
    MOCK_METHOD2(sendRequest, APIPOLLER::HttpResponse*(APIPOLLER::HttpRequest::Method method, const APIPOLLER::String& url));
    MOCK_CONST_METHOD0(encodeParameters, APIPOLLER::settings_t*());
    MOCK_CONST_METHOD0(buildQueryString, APIPOLLER::String());

protected:
    void open() {}
    void close() {}
};

#endif
