#include <json/json.h>
#include "Pollers/Configuration/PollerSettingsBuilder.h"


APIPOLLER::PollerSettingsBuilder::PollerSettingsBuilder(Json::Value* json) {
    jsonNode = json;
}

APIPOLLER::PollerSettings* APIPOLLER::PollerSettingsBuilder::build()
{
    if (jsonNode->empty())
        return nullptr;

    settings = pollerSettingsMapper->from(*jsonNode);

    return settings;
}



