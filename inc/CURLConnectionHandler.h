#ifndef APIPOLLER_CURLCONNECTIONHANDLER_H
#define APIPOLLER_CURLCONNECTIONHANDLER_H

#include "APIPoller.h"

namespace APIPOLLER {
    class CURLConnectionHandler;
}

class APIPOLLER::CURLConnectionHandler
{
public:
    ~CURLConnectionHandler() {
        if (instance != nullptr)
            delete instance;
    };

    static CURLConnectionHandler* getInstance();

    bool init(CURLcode& curlCode);
    void destroy();
    bool isGloballyInitialized();

private:
    static CURLConnectionHandler* instance;
    bool globallyInitialized = false;

    CURLConnectionHandler() { };
    CURLConnectionHandler& operator=(const CURLConnectionHandler&) = delete;
    CURLConnectionHandler(const CURLConnectionHandler&) = delete;

};

#endif
