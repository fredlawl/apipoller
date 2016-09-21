#ifndef APIPOOLER_HTTPREQUESTCONFIGURATIONJSONMAPPER_H
#define APIPOOLER_HTTPREQUESTCONFIGURATIONJSONMAPPER_H

#include <Mappers/JsonDataMapper.h>
#include <Http/HttpRequestConfiguration.h>

namespace APIPOLLER
{
    class HttpRequestConfigurationJsonMapper : public JsonDataMapper<HttpRequestConfiguration>
    {
    public:
        HttpRequestConfiguration from(const Json::Value& json) const
        {
            HttpRequestConfiguration config;
            config.url = json["url"].asString();
            return config;
        }
    };
}

#endif
