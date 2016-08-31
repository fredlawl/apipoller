#ifndef APIPOLLER_CURLCONNECTIONHANDLER_H
#define APIPOLLER_CURLCONNECTIONHANDLER_H

#include "APIPoller.h"

namespace APIPOLLER {
    class CURLHandler;
}

class APIPOLLER::CURLHandler
{
public:
    ~CURLHandler() {
        if (instance != nullptr)
            delete instance;
    };

    static CURLHandler* getInstance();

    bool init(CURLcode& curlCode);
    void destroy();
    bool isGloballyInitialized();

private:
    static CURLHandler* instance;
    bool globallyInitialized = false;

    CURLHandler() { };
    CURLHandler& operator=(const CURLHandler&) = delete;
    CURLHandler(const CURLHandler&) = delete;

};

#endif
