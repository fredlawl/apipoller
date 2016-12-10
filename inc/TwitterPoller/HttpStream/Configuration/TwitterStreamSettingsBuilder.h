#ifndef APIPOOLER_JSONTWITTERSTREAMSETTINGSBUILDER_H
#define APIPOOLER_JSONTWITTERSTREAMSETTINGSBUILDER_H

#include <TwitterPoller/Configuration/ITwitterSettingsBuilder.h>
#include <TwitterPoller/Mappers/TwitterSettingsMapper.h>
#include "Http/Mappers/HttpRequestSettingsMapper.h"
#include "Configuration/BaseSettingsBuilder.h"
#include "Mappers/DataMapper.h"
#include "Http/Configuration/HttpRequestSettings.h"
#include "TwitterHttpStreamSettings.h"
#include "Http/Configuration/IHttpSettingsBuilder.h"

namespace APIPOLLER {
    class TwitterStreamSettingsBuilder;
}

class APIPOLLER::TwitterStreamSettingsBuilder :
        BaseSettingsBuilder<TwitterHttpStreamSettings>,
        IHttpSettingsBuilder<TwitterStreamSettingsBuilder>,
        ITwitterSettingsBuilder<TwitterStreamSettingsBuilder>
{
public:
    TwitterStreamSettingsBuilder(Json::Value* json);

    ~TwitterStreamSettingsBuilder()
    {
        delete httpSettingsMapper;
        delete twitterSettingsMapper;
    }

    TwitterStreamSettingsBuilder* withHttpSettings();
    TwitterStreamSettingsBuilder* withTwitterSettings();

    TwitterHttpStreamSettings* build();

private:
    TwitterHttpStreamSettings* settings = new TwitterHttpStreamSettings();
    const Json::Value* jsonNode = nullptr;

    DataMapper<Json::Value, HttpRequestSettings>* httpSettingsMapper = new HttpRequestSettingsMapper();
    DataMapper<Json::Value, TwitterSettings>* twitterSettingsMapper = new TwitterSettingsMapper();
};

#endif
