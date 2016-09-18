#ifndef APIPOOLER_POLLERFACTORY_H
#define APIPOOLER_POLLERFACTORY_H

#include "APIPoller.h"

namespace APIPOLLER {
    class PollerFactory;
    class Poller;
}

class APIPOLLER::PollerFactory
{
public:
    virtual ~PollerFactory() {}

    inline virtual Poller* createHttpPoller() const = 0;
    inline virtual Poller* createSocketPoller() const = 0;
    inline virtual Poller* createHttpStreamPoller() const = 0;

protected:
    PollerFactory() {}
};

#endif
