#include "Pollers/TwitterPoller.h"
#include "Pollers/TwitterStreamReader.h"
#include "Http/HttpRequest.h"
#include "CURLHandler.h"

APIPOLLER::String APIPOLLER::TwitterPoller::authString = "";


APIPOLLER::TwitterPoller::TwitterPoller(HttpRequest* requestEngine)
{
    this->requestEngine = requestEngine;
}


APIPOLLER::TwitterPoller::~TwitterPoller()
{

}


bool APIPOLLER::TwitterPoller::fetch()
{
    requestEngine->sendGetRequest("http://test.com");
    return true;
}


bool APIPOLLER::TwitterPoller::openConnection()
{
    CURLcode code;
    if (!CurlHandler::getInstance()->init(code)) {
        // todo: do something if error...
    }

    return (code == CURLE_OK);
}


void APIPOLLER::TwitterPoller::setOAuthTimestamp()
{
    APIPOLLER::timepoint_t now = std::chrono::system_clock::now();
    std::chrono::system_clock::duration dur = now.time_since_epoch();
    auto secondsSinceEpoch = dur.count() * std::chrono::system_clock::period::num / std::chrono::system_clock::period::den;
    credentials["oauth_timestamp"] = std::to_string(secondsSinceEpoch);
}


bool APIPOLLER::TwitterPoller::closeConnection()
{
    CurlHandler::getInstance()->destroy();
    return true;
}


bool APIPOLLER::TwitterPoller::testConnection()
{
    std::cout << "Testing connection" << std::endl;
    return true;
}


void APIPOLLER::TwitterPoller::buildAuthString()
{
    authString = "";
    uint8_t count = 0;

    for (const auto& part : credentials) {
        if (count > 0) {
            authString += ", ";
        }

        authString += part.first + "=\"" + part.second + "\"";
        ++count;
    }
}


APIPOLLER::String APIPOLLER::TwitterPoller::getAuthString()
{
    return authString;
}


bool APIPOLLER::TwitterPoller::reopenConnection()
{
    closeConnection();
    return openConnection();
}


APIPOLLER::String APIPOLLER::TwitterPoller::getName()
{
    return "Twitter API Poller";
}
