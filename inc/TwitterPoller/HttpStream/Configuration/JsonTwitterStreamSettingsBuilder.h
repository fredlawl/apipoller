#ifndef APIPOOLER_JSONTWITTERSTREAMSETTINGSBUILDER_H
#define APIPOOLER_JSONTWITTERSTREAMSETTINGSBUILDER_H

#include "Http/Mappers/HttpRequestSettingsJsonMapper.h"
#include "Configuration/BaseSettingsBuilder.h"
#include "Mappers/JsonDataMapper.h"
#include "Http/Configuration/HttpRequestSettings.h"
#include "TwitterHttpStreamSettings.h"
#include "Http/Configuration/IHttpSettingsBuilder.h"

namespace APIPOLLER {
    class JsonTwitterStreamSettingsBuilder;
}

class APIPOLLER::JsonTwitterStreamSettingsBuilder :
        BaseSettingsBuilder<TwitterHttpStreamSettings>,
        IHttpSettingsBuilder<JsonTwitterStreamSettingsBuilder>
{
public:
    JsonTwitterStreamSettingsBuilder(Json::Value* json);

    ~JsonTwitterStreamSettingsBuilder()
    {
        delete httpSettingsMapper;
    }

    JsonTwitterStreamSettingsBuilder* withHttpSettings();

    TwitterHttpStreamSettings* build();

private:
    TwitterHttpStreamSettings* settings = new TwitterHttpStreamSettings();
    const Json::Value* jsonNode = nullptr;
    JsonDataMapper<HttpRequestSettings>* httpSettingsMapper = new HttpRequestSettingsJsonMapper();
};

#endif
