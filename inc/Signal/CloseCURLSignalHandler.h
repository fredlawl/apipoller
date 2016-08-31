#ifndef APIPOLLER_CLOSECURLSIGNALHANDLER_H
#define APIPOLLER_CLOSECURLSIGNALHANDLER_H

#include "../GlobalIncludes.h"
#include "ISignalHandler.h"

namespace APIPOLLER {
    class CloseCURLSignalHandler;
}

class APIPOLLER::CloseCURLSignalHandler : public ISignalHandler {
public:
    void handle(int signum);
};

#endif
