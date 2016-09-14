#ifndef APIPOLLER_TWITTERPOLLER_H
#define APIPOLLER_TWITTERPOLLER_H

#include "Poller.h"

namespace APIPOLLER {
    class TwitterPoller;
}

class APIPOLLER::TwitterPoller : public Poller
{
public:
    TwitterPoller(Configuration* configuration) : Poller(configuration) {};
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

    void setOAuthTimestamp();

};

#endif
