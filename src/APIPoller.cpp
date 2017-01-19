#include <Pollers/Configuration/PollerSettings.h>
#include <Signal/SignalManager.h>
#include <Signal/CloseCURLSignalHandler.h>
#include <Pollers/PollerFactoryCreator.h>
#include <Pollers/Poller.h>
#include <Loggers/STDLogger.h>
#include <Configuration/JsonConfigurationReader.h>
#include <Pollers/Configuration/PollerSettingsBuilder.h>

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

    // Declare system logger
    ILogger* systemLogger = new STDLogger();

    // Load in app configuration file
    String configPath = "../configurations/test.json";
    Json::Reader jsonReader;
    JsonConfigurationReader configReader(&jsonReader);
    Json::Value* globalConfiguration = nullptr;
    if ( (globalConfiguration = configReader.loadFromFile(configPath)) == nullptr) {
        systemLogger->logError("Unable to load configuration file at path \"" + configPath + "\"");
    }

    // Create poller settings
    PollerSettingsBuilder pollerSettingsBuilder(globalConfiguration);
    PollerSettings* pollerSettings = pollerSettingsBuilder.build();

    // Initiate Poller
    PollerFactoryCreator factoryCreator;
    IPollerFactory* pollerFactory = nullptr;
    Poller* poller = nullptr;

    // Grab a poller
    if ((pollerFactory = factoryCreator.getFactory(pollerSettings->poller)) == nullptr) {
        systemLogger->logError("Service \"" + pollerSettings->poller + "\" does not exist in the system.");
        return EXIT_FAILURE;
    }

    // Grab a poller type
    if ((poller = factoryCreator.getType(pollerFactory, pollerSettings->type)) == nullptr) {
        systemLogger->logError("The service type \"" + pollerSettings->poller + "\" does not exist for \"" + pollerSettings->type + "\".");
        return EXIT_FAILURE;
    }

    // Delete global json configuration after it's been mapped out
    delete globalConfiguration;
    delete pollerSettings;

    String pollerName = poller->getName();
    systemLogger->logMessage(pollerName + " has started.");
    if (!poller->run()) {
        systemLogger->logMessage(pollerName + " stopped.");
    }

    return EXIT_SUCCESS;
}