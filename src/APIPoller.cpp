#include <Pollers/PollerConfiguration.h>
#include <Signal/SignalManager.h>
#include <Signal/CloseCURLSignalHandler.h>
#include <Pollers/PollerFactoryCreator.h>
#include <Loggers/STDLogger.h>
#include <Configuration/JsonConfigurationReader.h>
#include <Pollers/Mappers/PollerConfigurationJsonMapper.h>
#include <Http/Mappers/HttpRequestConfigurationJsonMapper.h>
#include <Http/HttpRequestConfiguration.h>

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

    PollerConfigurationJsonMapper pollerConfigMapper;
    auto pollerConfig = pollerConfigMapper.from(globalConfiguration);

//    HttpRequestConfigurationJsonMapper requestMapper;
//    Json::Value requestConfig = globalConfiguration->get("request", "");
//    auto httpRequestConfig = requestMapper.from(&requestConfig);
//
//    systemLogger->logMessage(httpRequestConfig.url);

    // Delete global json configuration after it's been mapped out
    delete globalConfiguration;

    // Initiate Poller
    PollerFactoryCreator factoryCreator;
    PollerFactory* pollerFactory = nullptr;
    Poller* poller = nullptr;

    // Grab a poller
    if ((pollerFactory = factoryCreator.getFactory(pollerConfig.poller)) == nullptr) {
        systemLogger->logError("Service \"" + pollerConfig.poller + "\" does not exist in the system.");
        return EXIT_FAILURE;
    }

    // Grab a poller type
    if ((poller = factoryCreator.getType(pollerFactory, pollerConfig.type)) == nullptr) {
        systemLogger->logError("The service type \"" + pollerConfig.poller + "\" does not exist for \"" + pollerConfig.type + "\".");
        return EXIT_FAILURE;
    }

    String pollerName = poller->getName();
    systemLogger->logMessage(pollerName + " has started.");
    if (!poller->run()) {
        systemLogger->logMessage(pollerName + " stopped.");
    }

    return EXIT_SUCCESS;
}