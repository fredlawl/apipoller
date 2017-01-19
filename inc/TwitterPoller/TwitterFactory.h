#ifndef APIPOOLER_TWITTERFACTORY_H
#define APIPOOLER_TWITTERFACTORY_H

#include "TwitterPoller/HttpStream/TwitterHttpStreamPoller.h"

namespace APIPOLLER {
    class TwitterFactory;
    class IPollerFactory;
}

class APIPOLLER::TwitterFactory : public IPollerFactory
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
