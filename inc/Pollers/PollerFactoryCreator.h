#ifndef APIPOOLER_POLLERCREATOR_H
#define APIPOOLER_POLLERCREATOR_H

#include "TwitterPoller/TwitterFactory.h"

namespace APIPOLLER {
    class PollerFactoryCreator;
}

class APIPOLLER::PollerFactoryCreator
{
public:
    PollerFactory* getFactory(const String& factoryType) const
    {
        if (factoryType.compare("twitter") == 0) {
            return new TwitterFactory();
        }

        return nullptr;
    }


    Poller* getType(PollerFactory* factory, const String& pollerType) const
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
};

#endif
