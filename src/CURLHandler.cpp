#include "../inc/CURLHandler.h"

APIPOLLER::CURLHandler* APIPOLLER::CURLHandler::instance = nullptr;

APIPOLLER::CURLHandler *APIPOLLER::CURLHandler::getInstance()
{
    if (instance == nullptr) {
        instance = new APIPOLLER::CURLHandler();
    }

    return instance;
}


bool APIPOLLER::CURLHandler::init(CURLcode& curlCode)
{
    curlCode = curl_global_init(CURL_GLOBAL_ALL);
    if (curlCode == CURLE_OK) {
        globallyInitialized = true;
    }

    return (curlCode == CURLE_OK);
}


void APIPOLLER::CURLHandler::destroy()
{
    if (!isGloballyInitialized()) {
        return;
    }

    globallyInitialized = false;
    curl_global_cleanup();
}


bool APIPOLLER::CURLHandler::isGloballyInitialized()
{
    return globallyInitialized;
}





