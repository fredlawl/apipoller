#ifndef APIPOLLER_POLLER_H
#define APIPOLLER_POLLER_H

#include "APIPoller.h"

namespace APIPOLLER {
    class Poller;
    class Configuration;
}

class APIPOLLER::Poller
{
public:
    virtual ~Poller() { }

    virtual bool run();
    virtual void loop();

    virtual String getName() = 0;
    virtual bool fetch() = 0;
    virtual bool openConnection() = 0;
    virtual bool closeConnection() = 0;
    virtual bool testConnection() = 0;
    virtual bool reopenConnection() = 0;

protected:
    Configuration* config;

    Poller(Configuration* configuration) : config(configuration) {}

};

#endif
