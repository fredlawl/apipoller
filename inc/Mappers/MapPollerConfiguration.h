#ifndef APIPOOLER_MAPPOLLERCONFIGURATION_H
#define APIPOOLER_MAPPOLLERCONFIGURATION_H

#include <Pollers/PollerConfiguration.h>
#include "Pollers/PollerConfiguration.h"
#include "json/json.h"

namespace APIPOLLER {
    class MapPollerConfiguration;
}

class APIPOLLER::MapPollerConfiguration
{
public:
    inline static PollerConfiguration map(Json::Value* json)
    {
        PollerConfiguration config;
        config.poller = json->get("poller", "").asString();
        config.type = json->get("type", "").asString();
        return config;
    }
};

#endif
