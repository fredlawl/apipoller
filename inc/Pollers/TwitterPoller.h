#ifndef APIPOLLER_TWITTERPOLLER_H
#define APIPOLLER_TWITTERPOLLER_H

#include <iostream>
#include <chrono>
#include <unordered_map>
#include "../APIPoller.h"
#include "../Http/HttpRequest.h"
#include "../Encoders/IEncoder.h"
#include "Poller.h"

namespace APIPOLLER {
    class TwitterPoller;
}

class APIPOLLER::TwitterPoller : public Poller
{
public:
    TwitterPoller(HttpRequest* httpRequest, IEncoder* encoder);
    TwitterPoller();
    ~TwitterPoller();

    String getAuthString();
    String getName();

    bool fetch();
    bool openConnection();
    bool closeConnection();
    bool testConnection();
    bool reopenConnection();

    void buildAuthString();

private:
    static String authString;
    settings_t credentials;
    HttpRequest* request = nullptr;

    void setOAuthTimestamp();

};

#endif
