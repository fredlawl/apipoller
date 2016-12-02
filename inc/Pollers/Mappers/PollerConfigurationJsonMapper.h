#ifndef APIPOOLER_POLLERCONFIGURATIONJSONMAPPER_H
#define APIPOOLER_POLLERCONFIGURATIONJSONMAPPER_H

#include <Mappers/DataMapper.h>
#include <Pollers/PollerConfiguration.h>

namespace APIPOLLER
{
    class PollerConfigurationJsonMapper : public DataMapper<Json::Value, PollerConfiguration>
    {
    public:
        PollerConfiguration* from(const Json::Value& json) const
        {
            PollerConfiguration* config = new PollerConfiguration;
            config->poller = json["poller"].asString();
            config->type = json["type"].asString();
            return config;
        }
    };
}

#endif
