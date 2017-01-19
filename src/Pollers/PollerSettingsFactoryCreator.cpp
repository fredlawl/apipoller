#include "Pollers/ISettingsBuilderFactory.h"
#include "Pollers/PollerSettingsFactoryCreator.h"
#include "TwitterPoller/TwitterSettingsBuilderFactory.h"

APIPOLLER::ISettingsBuilderFactory* APIPOLLER::PollerSettingsFactoryCreator::getFactory(const String& factoryType, void* config) const
{
	if (factoryType.compare("twitter") == 0) {
		return new TwitterSettingsBuilderFactory(config);
	}

	return nullptr;
}


void* APIPOLLER::PollerSettingsFactoryCreator::getType(ISettingsBuilderFactory* factory, const String& pollerType) const
{
	if (pollerType.compare("http") == 0) {
		return factory->createHttpSettingsBuilder();
	} else if (pollerType.compare("socket")  == 0) {
		return factory->createSocketSettingsBuilder();
	} else if (pollerType.compare("stream") == 0) {
		return factory->createHttpStreamSettingsBuilder();
	}

	return nullptr;
}