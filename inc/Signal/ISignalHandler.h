#ifndef APIPOLLER_ISIGNALHANDLER_H
#define APIPOLLER_ISIGNALHANDLER_H

#include <cstdlib>
#include <csignal>

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
