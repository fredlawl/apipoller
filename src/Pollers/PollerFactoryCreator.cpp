#include "Pollers/IPollerFactory.h"
#include "Pollers/PollerFactoryCreator.h"
#include "TwitterPoller/TwitterFactory.h"

APIPOLLER::IPollerFactory* APIPOLLER::PollerFactoryCreator::getFactory(const String& factoryType) const
{
    if (factoryType.compare("twitter") == 0) {
        return new TwitterFactory();
    }

    return nullptr;
}


APIPOLLER::Poller* APIPOLLER::PollerFactoryCreator::getType(IPollerFactory* factory, const String& pollerType) const
{
    if (pollerType.compare("http") == 0) {
        return factory->createHttpPoller();
    } else if (pollerType.compare("socket")  == 0) {
        return factory->createSocketPoller();
    } else if (pollerType.compare("stream") == 0) {
        return factory->createHttpStreamPoller();
    }

    return nullptr;
}