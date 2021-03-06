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
     * Function to write data from a response stream.
     *
     * @param void* contents
     * @param size_t sizeOfBlock
     * @param size_t numberOfBlocks
     * @param void* stringBuffer
     *
     * @return size_t Bytes written
     */
    static size_t writeToString(void* contents, size_t sizeOfBlock, size_t numberOfBlocks, void* stringBuffer);


    /**
     * Function to write data from a response stream.
     *
     * @param void* contents
     * @param size_t sizeOfBlock
     * @param size_t numberOfBlocks
     * @param void* settingsContainer
     *
     * @return size_t Bytes written
     */
    static size_t writeToSettings(void* contents, size_t sizeOfBlock, size_t numberOfBlocks, void* settingsContainer);


    /**
     * Function to write data from a response stream.
     *
     * @param void* contents
     * @param size_t sizeOfBlock
     * @param size_t numberOfBlocks
     * @param void* streamReader
     *
     * @return size_t Bytes written
     */
    static size_t writeToStreamReader(void* contents, size_t sizeOfBlock, size_t numberOfBlocks, void* streamReader);


    /**
     * Function to write NO data to ANYTHING
     *
     * @param void* contents
     * @param size_t sizeOfBlock
     * @param size_t numberOfBlocks
     * @param void* doNotCast
     *
     * @return size_t Bytes written
     */
    static size_t writeToNothing(void* contents, size_t sizeOfBlock, size_t numberOfBlocks, void* doNotCast);


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
