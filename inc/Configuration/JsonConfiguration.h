#ifndef APIPOOLER_JSONCONFIGURATION_H
#define APIPOOLER_JSONCONFIGURATION_H

#include "Configuration.h"
#include "json/json.h"

namespace APIPOLLER {
    class JsonConfiguration;
}

class APIPOLLER::JsonConfiguration : public Configuration, public Json::Value
{
public:
    JsonConfiguration() {}
    ~JsonConfiguration() {}

    Configuration* get(const String& key) const;
    void set(const String& key, const String& value);

};

#endif
