#include "../inc/CurlHandler.h"
#include "../inc/Pollers/IStreamReader.h"
#include "../inc/Utility.h"

APIPOLLER::CurlHandler* APIPOLLER::CurlHandler::instance = nullptr;

APIPOLLER::CurlHandler *APIPOLLER::CurlHandler::getInstance()
{
    if (instance == nullptr) {
        instance = new APIPOLLER::CurlHandler();
    }

    return instance;
}


bool APIPOLLER::CurlHandler::init(CURLcode& curlCode)
{
    curlCode = curl_global_init(CURL_GLOBAL_ALL);
    if (curlCode == CURLE_OK) {
        globallyInitialized = true;
    }

    return (curlCode == CURLE_OK);
}


void APIPOLLER::CurlHandler::destroy()
{
    if (!isGloballyInitialized()) {
        return;
    }

    globallyInitialized = false;
    curl_global_cleanup();
}


bool APIPOLLER::CurlHandler::isGloballyInitialized()
{
    return globallyInitialized;
}


size_t APIPOLLER::CurlHandler::writeToString(void *contents, size_t sizeOfBlock, size_t numberOfBlocks, void *stringBuffer)
{
    size_t totalSize = sizeOfBlock * numberOfBlocks;
    ((String*) stringBuffer)->append((char*) contents, totalSize);
    return totalSize;
}


size_t APIPOLLER::CurlHandler::writeToSettings(void *contents, size_t sizeOfBlock, size_t numberOfBlocks, void *settingsContainer)
{
    size_t totalSize = sizeOfBlock * numberOfBlocks;
    String header = String((char *) contents, totalSize);
    settings_t *headers = ((settings_t *) settingsContainer);

    StringArray parts = APIPOLLER::Utility::splitAtDelimiterOnce(header, ':');
    if (parts.empty()) {
        return totalSize;
    }

    headers->emplace(parts[0], parts[1]);

    return totalSize;
}


size_t APIPOLLER::CurlHandler::writeToStreamReader(void *contents, size_t sizeOfBlock, size_t numberOfBlocks, void* streamReader)
{
    size_t totalSize = sizeOfBlock * numberOfBlocks;
    String contentAsString = String((char*) contents, totalSize);
    IStreamReader* reader = ((APIPOLLER::IStreamReader*) streamReader);
    reader->readString(contentAsString);
    return totalSize;
}


size_t APIPOLLER::CurlHandler::writeToNothing(void *contents, size_t sizeOfBlock, size_t numberOfBlocks, void *doNotCast)
{
    return sizeOfBlock * numberOfBlocks;
}



