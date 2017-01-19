#ifndef APIPOOLER_POLLERSETTINGSFACTORYCREATOR_H
#define APIPOOLER_POLLERSETTINGSFACTORYCREATOR_H


#include "APIPoller.h"
#include "Configuration/ISettingsBuilder.h"

namespace APIPOLLER {
	class PollerSettingsFactoryCreator;
	class ISettingsBuilderFactory;
}

class APIPOLLER::PollerSettingsFactoryCreator
{
public:
	ISettingsBuilderFactory* getFactory(const String& factoryType, void* config) const;
	void* getType(ISettingsBuilderFactory* factory, const String& pollerType) const;
};

#endif
