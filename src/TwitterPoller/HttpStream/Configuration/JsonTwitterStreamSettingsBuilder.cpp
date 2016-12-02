#include <json/json.h>
#include "TwitterPoller/HttpStream/Configuration/JsonTwitterStreamSettingsBuilder.h"

APIPOLLER::JsonTwitterStreamSettingsBuilder::JsonTwitterStreamSettingsBuilder(Json::Value* json) {
    jsonNode = json;
}

APIPOLLER::JsonTwitterStreamSettingsBuilder* APIPOLLER::JsonTwitterStreamSettingsBuilder::withHttpSettings()
{
    Json::Value node = jsonNode->get("http", "");
    if (node.empty())
        return this;

    HttpRequestSettings* requestSettings = httpSettingsMapper->from(node);
    settings->requestConfiguration = *requestSettings;

    delete requestSettings;
    return this;
}

APIPOLLER::TwitterHttpStreamSettings* APIPOLLER::JsonTwitterStreamSettingsBuilder::build()
{
    return settings;
}



