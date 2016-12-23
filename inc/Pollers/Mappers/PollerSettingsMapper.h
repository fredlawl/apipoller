#ifndef APIPOOLER_POLLERMAPPER_H
#define APIPOOLER_POLLERMAPPER_H

#include <Mappers/DataMapper.h>
#include <Pollers/Configuration/PollerSettings.h>

namespace APIPOLLER
{
    class PollerSettingsMapper : public DataMapper<Json::Value, PollerSettings>
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
