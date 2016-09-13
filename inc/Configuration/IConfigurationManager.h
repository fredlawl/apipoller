#ifndef APIPOOLER_ICONFIGURATIONMANAGER_H
#define APIPOOLER_ICONFIGURATIONMANAGER_H

#include "Configuration.h"

namespace APIPOLLER {
    class IConfigurationManager;
}

class APIPOLLER::IConfigurationManager
{
public:
    virtual ~IConfigurationManager() {}

    virtual Configuration* loadFromFile(const String& path) const = 0;

protected:
    IConfigurationManager() {};
};

#endif
