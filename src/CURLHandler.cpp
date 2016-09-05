#include "../inc/CurlHandler.h"

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
    ((String*) stringBuffer)->append((char*) contents, sizeOfBlock * numberOfBlocks);
    return sizeOfBlock * numberOfBlocks;
}


size_t APIPOLLER::CurlHandler::writeToSettings(void *contents, size_t sizeOfBlock, size_t numberOfBlocks, void *settingsContainer)
{
    // ... stub
    return sizeOfBlock * numberOfBlocks;
}


size_t APIPOLLER::CurlHandler::writeToStreamReader(void *contents, size_t sizeOfBlock, size_t numberOfBlocks, void* streamReader)
{
    String contentAsString = String((char*) contents, sizeOfBlock * numberOfBlocks);
    IStreamReader* reader = ((APIPOLLER::IStreamReader*) streamReader);
    reader->readString(contentAsString);
    return sizeOfBlock * numberOfBlocks;
}

