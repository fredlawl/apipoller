#ifndef APIPOOLER_TWITTERSETTINGS_H
#define APIPOOLER_TWITTERSETTINGS_H

#include "APIPoller.h"

namespace APIPOLLER {
    typedef struct {
        String consumerKey;
        String consumerSecret;

        // Collected on first round to twitter auth; does not need mapping
        String bearerToken;
    } TwitterSettings;
}

#endif
