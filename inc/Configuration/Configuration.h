#ifndef APIPOOLER_CONFIGURATION_H
#define APIPOOLER_CONFIGURATION_H

#include "APIPoller.h"

namespace APIPOLLER {
    class Configuration;
}

class APIPOLLER::Configuration
{
public:
    virtual ~Configuration() {}

    virtual Configuration* get(const String& key) const = 0;
    virtual void set(const String& key, const String& value) = 0;

protected:
    Configuration() {}
};

#endif
