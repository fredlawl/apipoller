#ifndef APIPOOLER_JSONCONFIGURATIONMANAGER_H
#define APIPOOLER_JSONCONFIGURATIONMANAGER_H

#include "IConfigurationManager.h"

namespace APIPOLLER {
    class JsonConfigurationManager;
}


class APIPOLLER::JsonConfigurationManager
{
public:
    Configuration* loadFromFile(const String& path);
    ~JsonConfigurationManager() {}
};

#endif
