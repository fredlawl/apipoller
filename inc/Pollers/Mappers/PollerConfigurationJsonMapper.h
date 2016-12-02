#ifndef APIPOOLER_POLLERCONFIGURATIONJSONMAPPER_H
#define APIPOOLER_POLLERCONFIGURATIONJSONMAPPER_H

#include <Mappers/DataMapper.h>
#include <Pollers/Configuration/PollerSettings.h>

namespace APIPOLLER
{
    class PollerConfigurationJsonMapper : public DataMapper<Json::Value, PollerSettings>
    {
    public:
        PollerSettings* from(const Json::Value& json) const
        {
            PollerSettings* config = new PollerSettings;
            config->poller = json["poller"].asString();
            config->type = json["type"].asString();
            return config;
        }
    };
}

#endif
