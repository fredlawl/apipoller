#include "Pollers/TwitterHttpStreamPoller.h"
#include "Signal/SignalManager.h"
#include "Signal/CloseCURLSignalHandler.h"
#include "Pollers/PollerFactoryCreator.h"
#include "Loggers/STDLogger.h"

int main (int argc, char** argv)
{
    using namespace std;
    using namespace APIPOLLER;

    srand(time(NULL));

    // Handle CURL after a prompt abort
    CloseCURLSignalHandler curlSignalHandler;
    SignalManager::getInstance()->registerHandler(SIGINT, &curlSignalHandler);
    SignalManager::getInstance()->registerHandler(SIGQUIT, &curlSignalHandler);
    SignalManager::getInstance()->registerHandler(SIGABRT, &curlSignalHandler);
    SignalManager::getInstance()->registerHandler(SIGHUP, &curlSignalHandler);

    ILogger* systemLogger = new STDLogger();

    // todo: move these to some sort of settings object
    String pollerService = "twitter";
    String pollerServiceType = "stream";
    String pollerName;

    PollerFactoryCreator factoryCreator;
    PollerFactory* pollerFactory = nullptr;
    Poller* poller = nullptr;

    // Grab a service
    if ((pollerFactory = factoryCreator.getFactory(pollerService)) == nullptr) {
        systemLogger->logError("Service \"" + pollerService + "\" does not exist in the system.");
        return EXIT_FAILURE;
    }

    // Grab a service type
    if ((poller = factoryCreator.getType(pollerFactory, pollerServiceType)) == nullptr) {
        systemLogger->logError("The service type \"" + pollerServiceType + "\" does not exist for \"" + pollerService + "\".");
        return EXIT_FAILURE;
    }

    pollerName = poller->getName();
    systemLogger->logMessage(pollerName + " has started.");
    if (!poller->run()) {
        systemLogger->logMessage(pollerName + " stopped.");
    }

    return EXIT_SUCCESS;
}