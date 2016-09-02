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

    /**
     * Function to write data to a buffer from CURL.
     *
     * @param void* contents Stream contents coming in
     * @param size_t size Size of individual block
     * @param size_t numberOfBlocks
     * @param void* buffer Buffer pointer should be passed a string. This doesn't have to be the case, but this will be dynamically casted to a string..
     *
     * @return size_t Bytes written
     *
     * @see http://stackoverflow.com/a/9786295/6018969
     */
    static size_t writeToString(void *contents, size_t size, size_t numberOfBlocks, void *buffer);


    /**
     * Function to write data to a buffer from CURL.
     *
     * @param void* contents Stream contents coming in
     * @param size_t size Size of individual block
     * @param size_t numberOfBlocks
     * @param void* buffer Buffer pointer should be passed a string. This doesn't have to be the case, but this will be dynamically casted to settings_t
     *
     * @return size_t Bytes written
     */
    static size_t writeToSettings(void *contents, size_t size, size_t numberOfBlocks, void *buffer);


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
