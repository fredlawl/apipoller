#ifndef APIPOOLER_TWITTERHTTPSTREAMSETTINGS_H
#define APIPOOLER_TWITTERHTTPSTREAMSETTINGS_H

#include "APIPoller.h"
#include "Http/Configuration/HttpRequestSettings.h"
#include "TwitterSettings.h"

namespace APIPOLLER {
    typedef struct {
        TwitterSettings twitterCredentials;
        HttpRequestSettings requestConfiguration;
        int16_t reconnectAttempts;
    } TwitterHttpStreamSettings;
}

#endif
