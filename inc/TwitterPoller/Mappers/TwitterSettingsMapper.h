#ifndef APIPOOLER_TWITTERSETTINGSMAPPER_H
#define APIPOOLER_TWITTERSETTINGSMAPPER_H

#include <TwitterPoller/Configuration/TwitterSettings.h>
#include <Mappers/DataMapper.h>
#include "json/json.h"

namespace APIPOLLER
{
    class TwitterSettingsMapper : public DataMapper<Json::Value, TwitterSettings>
    {
    public:
        TwitterSettings* from (const Json::Value& json) const
        {
            TwitterSettings* config = new TwitterSettings;
            config->consumerKey = json["consumerKey"].asString();
            config->consumerSecret = json["consumerSecret"].asString();
            return config;
        }
    };
}

#endif
