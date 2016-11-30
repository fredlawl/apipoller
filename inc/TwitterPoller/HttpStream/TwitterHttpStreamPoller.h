#ifndef APIPOLLER_TWITTERPOLLER_H
#define APIPOLLER_TWITTERPOLLER_H

#include "Pollers/Poller.h"
#include "TwitterPoller/HttpStream/Configuration/TwitterHttpStreamSettings.h"

namespace APIPOLLER {
    class TwitterHttpStreamPoller;
    class IEncoder;
    class IStreamReader;
}

class APIPOLLER::TwitterHttpStreamPoller : public Poller
{
public:
    TwitterHttpStreamPoller(const TwitterHttpStreamSettings& configuration) {};
    TwitterHttpStreamPoller() {};
    ~TwitterHttpStreamPoller();

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
    TwitterHttpStreamSettings configuration;
    settings_t credentials;

    void setOAuthTimestamp();

};

#endif
