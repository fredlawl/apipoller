#ifndef APIPOLLER_CURLCONNECTIONHANDLER_H
#define APIPOLLER_CURLCONNECTIONHANDLER_H

#include "APIPoller.h"

namespace APIPOLLER {
    class CurlHandler;
}

class APIPOLLER::CurlHandler
{
public:
    ~CurlHandler() {
        if (instance != nullptr)
            delete instance;
    };

    static CurlHandler* getInstance();

    bool init(CURLcode& curlCode);
    void destroy();
    bool isGloballyInitialized();

private:
    static CurlHandler* instance;
    bool globallyInitialized = false;

    CurlHandler() { };
    CurlHandler& operator=(const CurlHandler&) = delete;
    CurlHandler(const CurlHandler&) = delete;

};

#endif
