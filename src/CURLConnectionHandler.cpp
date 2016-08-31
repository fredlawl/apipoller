#include "../inc/CURLConnectionHandler.h"

APIPOLLER::CURLConnectionHandler* APIPOLLER::CURLConnectionHandler::instance = nullptr;

APIPOLLER::CURLConnectionHandler *APIPOLLER::CURLConnectionHandler::getInstance()
{
    if (instance == nullptr) {
        instance = new APIPOLLER::CURLConnectionHandler();
    }

    return instance;
}


bool APIPOLLER::CURLConnectionHandler::init(CURLcode& curlCode)
{
    curlCode = curl_global_init(CURL_GLOBAL_ALL);
    if (curlCode == CURLE_OK) {
        globallyInitialized = true;
    }

    return (curlCode == CURLE_OK);
}


void APIPOLLER::CURLConnectionHandler::destroy()
{
    if (!isGloballyInitialized()) {
        return;
    }

    globallyInitialized = false;
    curl_global_cleanup();
}


bool APIPOLLER::CURLConnectionHandler::isGloballyInitialized()
{
    return globallyInitialized;
}





