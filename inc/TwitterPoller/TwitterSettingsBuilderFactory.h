#ifndef APIPOOLER_TWITTERSETTINGSBUILDERFACTORY_H
#define APIPOOLER_TWITTERSETTINGSBUILDERFACTORY_H

#include <json/json.h>
#include "TwitterPoller/HttpStream/Configuration/TwitterStreamSettingsBuilder.h"

namespace APIPOLLER {
    class ISettingsBuilderFactory;
    class TwitterSettingsBuilderFactory;
}

class APIPOLLER::TwitterSettingsBuilderFactory : public ISettingsBuilderFactory
{
public:

    TwitterSettingsBuilderFactory(void* json) {
        configuration = (Json::Value*) json;
    };

    inline void* createSocketSettingsBuilder() const {
        return nullptr;
    }

    inline void* createHttpStreamSettingsBuilder() const {
        return new TwitterStreamSettingsBuilder(configuration);
    }

    inline void* createHttpSettingsBuilder() const {
        return nullptr;
    }

private:
    Json::Value* configuration = nullptr;
};

#endif
