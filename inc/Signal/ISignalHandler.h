#ifndef APIPOLLER_ISIGNALHANDLER_H
#define APIPOLLER_ISIGNALHANDLER_H

#include "../APIPoller.h"

namespace APIPOLLER {
    class ISignalHandler;
}


class APIPOLLER::ISignalHandler
{
public:
    virtual ~ISignalHandler() { };
    virtual void handle(int signum) = 0;
};

#endif
