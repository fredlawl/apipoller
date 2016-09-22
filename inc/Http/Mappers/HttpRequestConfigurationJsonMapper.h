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

            // Populate the query parameters
            for (String name : json["queryParameters"].getMemberNames()) {
                config.parameters[name] = json["queryParameters"][name].asString();
            }

            // todo: refactor later with a lookup
            String method = json["method"].asString();
            std::transform(method.begin(), method.end(), method.begin(), ::tolower);
            if (method == "post") {
                config.method = HttpRequest::Method::POST;
            } else if (method == "put") {
                config.method = HttpRequest::Method::PUT;
            } else if (method == "delete") {
                config.method = HttpRequest::Method::DELETE;
            } else {
                config.method = HttpRequest::Method::GET;
            }

            return config;
        }
    };
}

#endif
