#ifndef APIPOOLER_POLLERSETTINGSBUILDER_H
#define APIPOOLER_POLLERSETTINGSBUILDER_H

#include <json/json.h>
#include "Pollers/Mappers/PollerSettingsMapper.h"
#include "Mappers/DataMapper.h"
#include "Configuration/ISettingsBuilder.h"
#include "PollerSettings.h"

namespace APIPOLLER {
    class PollerSettingsBuilder;
}

class APIPOLLER::PollerSettingsBuilder : public ISettingsBuilder<PollerSettings>
{
public:
    PollerSettingsBuilder(Json::Value* json);
    ~PollerSettingsBuilder()
    {
        delete pollerSettingsMapper;
    }

    PollerSettings* build();

private:
    PollerSettings* settings = new PollerSettings();
    const Json::Value* jsonNode = nullptr;

    DataMapper<Json::Value, PollerSettings>* pollerSettingsMapper = new PollerSettingsMapper();
};


#endif
