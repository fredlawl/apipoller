#ifndef APIPOOLER_POLLERCONFIGURATIONJSONMAPPER_H
#define APIPOOLER_POLLERCONFIGURATIONJSONMAPPER_H

#include <Mappers/JsonDataMapper.h>
#include <Pollers/PollerConfiguration.h>

namespace APIPOLLER
{
    class PollerConfigurationJsonMapper : public JsonDataMapper<PollerConfiguration>
    {
    public:
        PollerConfiguration from(const Json::Value& json) const
        {
            PollerConfiguration config;
            config.poller = json["poller"].asString();
            config.type = json["type"].asString();
            return config;
        }
    };
}

#endif
