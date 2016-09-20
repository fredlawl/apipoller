#include "TwitterPoller/HttpStream/TwitterHttpStreamPoller.h"
#include "TwitterPoller/HttpStream/TwitterStreamReader.h"
#include "Http/HttpRequest.h"
#include "CURLHandler.h"

APIPOLLER::String APIPOLLER::TwitterHttpStreamPoller::authString = "";


APIPOLLER::TwitterHttpStreamPoller::~TwitterHttpStreamPoller()
{

}


bool APIPOLLER::TwitterHttpStreamPoller::fetch()
{

    return true;
}


bool APIPOLLER::TwitterHttpStreamPoller::openConnection()
{
    CURLcode code;
    if (!CurlHandler::getInstance()->init(code)) {
        // todo: do something if error...
    }

    return (code == CURLE_OK);
}


void APIPOLLER::TwitterHttpStreamPoller::setOAuthTimestamp()
{
    APIPOLLER::timepoint_t now = std::chrono::system_clock::now();
    std::chrono::system_clock::duration dur = now.time_since_epoch();
    auto secondsSinceEpoch = dur.count() * std::chrono::system_clock::period::num / std::chrono::system_clock::period::den;
    credentials["oauth_timestamp"] = std::to_string(secondsSinceEpoch);
}


bool APIPOLLER::TwitterHttpStreamPoller::closeConnection()
{
    CurlHandler::getInstance()->destroy();
    return true;
}


bool APIPOLLER::TwitterHttpStreamPoller::testConnection()
{
    std::cout << "Testing connection" << std::endl;
    return true;
}


void APIPOLLER::TwitterHttpStreamPoller::buildAuthString()
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


APIPOLLER::String APIPOLLER::TwitterHttpStreamPoller::getAuthString()
{
    return authString;
}


bool APIPOLLER::TwitterHttpStreamPoller::reopenConnection()
{
    closeConnection();
    return openConnection();
}


APIPOLLER::String APIPOLLER::TwitterHttpStreamPoller::getName()
{
    return "TwitterPoller API Poller";
}
