#include "../inc/APIPoller.h"
#include "../inc/Pollers/TwitterPoller.h"
#include "../inc/Signal/SignalManager.h"
#include "../inc/Signal/CloseCURLSignalHandler.h"
#include "../inc/Encoders/UrlEncoder.h"

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

    UrlEncoder encoder;
    Poller* twitter = new TwitterPoller(&encoder);

    // Show application is running
    std::cout << "Running " << twitter->getName() << std::endl;

    if (!twitter->run()) {
        std::cout << "Connection closed" << std::endl;
    }

    delete twitter;

    return EXIT_SUCCESS;
}