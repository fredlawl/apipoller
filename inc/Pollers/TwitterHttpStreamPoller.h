#ifndef APIPOLLER_TWITTERPOLLER_H
#define APIPOLLER_TWITTERPOLLER_H

#include "Poller.h"

namespace APIPOLLER {
    class TwitterHttpStreamPoller;
    class IEncoder;
    class IStreamReader;
}

class APIPOLLER::TwitterHttpStreamPoller : public Poller
{
public:
    TwitterHttpStreamPoller(Configuration* configuration) : Poller(configuration) {};
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
    settings_t credentials;

    void setOAuthTimestamp();

};

#endif
