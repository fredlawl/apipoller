#ifndef APIPOLLER_CLOSECURLSIGNALHANDLER_H
#define APIPOLLER_CLOSECURLSIGNALHANDLER_H

#include "ISignalHandler.h"

namespace APIPOLLER {
    class CloseCURLSignalHandler;
}

class APIPOLLER::CloseCURLSignalHandler : public ISignalHandler
{
public:
    void handle(int signum);
};

#endif
