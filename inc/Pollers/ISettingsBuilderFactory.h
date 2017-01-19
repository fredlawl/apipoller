#ifndef APIPOOLER_ISETTINGSBUILDERFACTORY_H
#define APIPOOLER_ISETTINGSBUILDERFACTORY_H

#include <Configuration/ISettingsBuilder.h>

namespace APIPOLLER {
    class ISettingsBuilderFactory;
}

class APIPOLLER::ISettingsBuilderFactory
{
public:
    virtual ~ISettingsBuilderFactory() {}

    inline virtual void* createSocketSettingsBuilder() const = 0;
    inline virtual void* createHttpStreamSettingsBuilder() const = 0;
    inline virtual void* createHttpSettingsBuilder() const = 0;

protected:
    ISettingsBuilderFactory() {}
};

#endif
