#ifndef APIPOLLER_ISIGNALMANAGER_H
#define APIPOLLER_ISIGNALMANAGER_H

#include "ISignalHandler.h"

namespace APIPOLLER {
    class SignalManager;
}

class APIPOLLER::SignalManager {
public:
    static SignalManager* getInstance();

    ~SignalManager();
    ISignalHandler* registerHandler(int signum, ISignalHandler* handler);
    int removeHandler(int signum);

private:
    static SignalManager* instance;
    static ISignalHandler* handlers[NSIG];

    SignalManager();
    static void dispatcher(int signum);
};

#endif