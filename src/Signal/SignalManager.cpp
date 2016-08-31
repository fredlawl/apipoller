
#include "../../inc/Signal/SignalManager.h"

APIPOLLER::SignalManager* APIPOLLER::SignalManager::instance = nullptr;
APIPOLLER::ISignalHandler* APIPOLLER::SignalManager::handlers[NSIG];


APIPOLLER::SignalManager::SignalManager()
{

}


APIPOLLER::SignalManager::~SignalManager()
{
    if (instance != nullptr)
        delete instance;
}


void APIPOLLER::SignalManager::dispatcher(int signum)
{
    // Perform a sanity check...
    if (SignalManager::handlers[signum] != 0) {
        // Dispatch the handler's hook method.
        SignalManager::handlers[signum]->handle(signum);
    }
}


APIPOLLER::ISignalHandler* APIPOLLER::SignalManager::registerHandler(int signum, APIPOLLER::ISignalHandler* handler)
{
    // Copy the <old_eh> from the <signum> slot in
    // the <signal_handlers_> table.
    ISignalHandler* prevHandler = SignalManager::handlers[signum];

    // Store <eh> into the <signum> slot in the
    // <signal_handlers_> table.
    SignalManager::handlers[signum] = handler;

    // Register the <dispatcher> to handle this
    // <signum>.
    struct sigaction sa;
    sa.sa_handler = SignalManager::dispatcher;
    sigemptyset (&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(signum, &sa, 0);

    return prevHandler;
}


int APIPOLLER::SignalManager::removeHandler(int signum)
{
    return 0;
}


APIPOLLER::SignalManager* APIPOLLER::SignalManager::getInstance()
{
    if (instance == nullptr)
        instance = new SignalManager;

    return instance;
}