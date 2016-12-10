#include <json/json.h>
#include "TwitterPoller/HttpStream/Configuration/TwitterStreamSettingsBuilder.h"

APIPOLLER::TwitterStreamSettingsBuilder::TwitterStreamSettingsBuilder(Json::Value* json) {
    jsonNode = json;
}

APIPOLLER::TwitterStreamSettingsBuilder* APIPOLLER::TwitterStreamSettingsBuilder::withHttpSettings()
{
    Json::Value node = jsonNode->get("http", "");
    if (node.empty())
        return this;

    HttpRequestSettings* requestSettings = httpSettingsMapper->from(node);
    settings->requestConfiguration = *requestSettings;

    delete requestSettings;
    return this;
}

APIPOLLER::TwitterStreamSettingsBuilder* APIPOLLER::TwitterStreamSettingsBuilder::withTwitterSettings()
{
    Json::Value node = jsonNode->get("twitter", "");
    if (node.empty())
        return this;

    TwitterSettings* twitterSettings = twitterSettingsMapper->from(node);
    settings->twitter = *twitterSettings;

    delete twitterSettings;
    return this;
}

APIPOLLER::TwitterHttpStreamSettings* APIPOLLER::TwitterStreamSettingsBuilder::build()
{
    return settings;
}



