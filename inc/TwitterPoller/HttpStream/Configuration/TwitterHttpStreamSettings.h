#ifndef APIPOOLER_TWITTERHTTPSTREAMSETTINGS_H
#define APIPOOLER_TWITTERHTTPSTREAMSETTINGS_H

#include "APIPoller.h"
#include "Http/Configuration/HttpRequestSettings.h"
#include "TwitterPoller/Configuration/TwitterSettings.h"

namespace APIPOLLER {
    typedef struct {
        TwitterSettings twitterConfiguration;
        HttpRequestSettings requestConfiguration;
        int16_t reconnectAttempts;
    } TwitterHttpStreamSettings;
}

#endif
