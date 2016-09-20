#ifndef APIPOOLER_POLLERCONFIGURATION_H
#define APIPOOLER_POLLERCONFIGURATION_H

#include "APIPoller.h"

namespace APIPOLLER {
    typedef struct {
        String poller;
        String type;
    } PollerConfiguration;
}

#endif
