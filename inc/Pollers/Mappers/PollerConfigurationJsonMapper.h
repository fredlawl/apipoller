#ifndef APIPOOLER_POLLERCONFIGURATIONJSONMAPPER_H
#define APIPOOLER_POLLERCONFIGURATIONJSONMAPPER_H

#include <Mappers/JsonDataMapper.h>
#include <Pollers/PollerConfiguration.h>

namespace APIPOLLER
{
    class PollerConfigurationJsonMapper : public JsonDataMapper<PollerConfiguration>
    {
    public:
        PollerConfiguration from(Json::Value* json) const
        {
            PollerConfiguration config;
            config.poller = json->get("poller", "").asString();
            config.type = json->get("type", "").asString();
            return config;
        }
    };
}

#endif
