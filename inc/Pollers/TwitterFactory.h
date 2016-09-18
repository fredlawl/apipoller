#ifndef APIPOOLER_TWITTERFACTORY_H
#define APIPOOLER_TWITTERFACTORY_H

#include "PollerFactory.h"
#include "TwitterHttpStreamPoller.h"

namespace APIPOLLER {
    class TwitterFactory;
}

class APIPOLLER::TwitterFactory : public PollerFactory
{
public:
    TwitterFactory() {}
    ~TwitterFactory() {}

    inline Poller* createHttpPoller() const
    {
        return nullptr;
    }

    inline Poller* createSocketPoller() const
    {
        return nullptr;
    }

    inline Poller* createHttpStreamPoller() const
    {
        return new TwitterHttpStreamPoller();
    }
};

#endif
