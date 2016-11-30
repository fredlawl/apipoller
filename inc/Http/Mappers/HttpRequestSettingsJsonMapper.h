#ifndef APIPOOLER_HTTPREQUESTSETTINGSJSONMAPPER_H
#define APIPOOLER_HTTPREQUESTSETTINGSJSONMAPPER_H

#include <Mappers/JsonDataMapper.h>
#include <Http/Configuration/HttpRequestSettings.h>

namespace APIPOLLER
{
    class HttpRequestSettingsJsonMapper : public JsonDataMapper<HttpRequestSettings>
    {
    public:
        HttpRequestSettings* from(const Json::Value& json) const
        {
            HttpRequestSettings* config = new HttpRequestSettings;
            config->url = json["url"].asString();

            // Populate the query parameters
            for (String name : json["queryParameters"].getMemberNames()) {
                config->parameters[name] = json["queryParameters"][name].asString();
            }

            // todo: refactor later with a lookup
            String method = json["method"].asString();
            std::transform(method.begin(), method.end(), method.begin(), ::tolower);
            if (method == "post") {
                config->method = HttpRequest::Method::POST;
            } else if (method == "put") {
                config->method = HttpRequest::Method::PUT;
            } else if (method == "delete") {
                config->method = HttpRequest::Method::DELETE;
            } else {
                config->method = HttpRequest::Method::GET;
            }

            return config;
        }
    };
}

#endif
