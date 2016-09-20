#ifndef APIPOOLER_HTTPREQUESTCONFIGURATION_H
#define APIPOOLER_HTTPREQUESTCONFIGURATION_H

#include "APIPoller.h"
#include "HttpRequest.h"

namespace APIPOLLER {
    typedef struct {
        String url;
        HttpRequest::Method method;
        settings_t parameters;
    } HttpRequestConfiguration;
}

#endif
