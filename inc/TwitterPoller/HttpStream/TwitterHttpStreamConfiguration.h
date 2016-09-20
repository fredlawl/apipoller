#ifndef APIPOOLER_TWITTERHTTPSTREAMCONFIGURATION_H
#define APIPOOLER_TWITTERHTTPSTREAMCONFIGURATION_H

#include "APIPoller.h"
#include "Http/HttpRequestConfiguration.h"
#include "TwitterPoller/TwitterConfiguration.h"

namespace APIPOLLER {
    typedef struct {
        TwitterConfiguration twitterCredentials;
        HttpRequestConfiguration requestConfiguration;
        int16_t reconnectAttempts;
    } TwitterHttpStreamConfiguration;
}

#endif
