#include "Pollers/TwitterPoller.h"
#include "Signal/SignalManager.h"
#include "Signal/CloseCURLSignalHandler.h"
#include "Configuration/JsonConfigurationManager.h"

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

    JsonConfigurationManager jsonConfigurationManager;
    Configuration* configuration = jsonConfigurationManager.loadFromFile("");
    Poller* twitter = new TwitterPoller(*configuration);

    // Show application is running
    std::cout << "Running " << twitter->getName() << std::endl;

    if (!twitter->run()) {
        std::cout << "Connection closed" << std::endl;
    }

    delete configuration;
    delete twitter;

    return EXIT_SUCCESS;
}