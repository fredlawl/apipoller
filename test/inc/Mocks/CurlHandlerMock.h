#ifndef APIPOOLER_CURLHANDLERMOCK_H_H
#define APIPOOLER_CURLHANDLERMOCK_H_H

#include "gmock/gmock.h"

#define private public
#include "CURLHandler.h"


class CurlHandlerMock : public APIPOLLER::CurlHandler
{
public:
    CurlHandlerMock() {};

    MOCK_METHOD0(getInstance, CurlHandler*());
    MOCK_METHOD4(writeToString, size_t(void* contents, size_t sizeOfBlock, size_t numberOfBlocks, void* stringBuffer));
    MOCK_METHOD4(writeToSettings, size_t(void* contents, size_t sizeOfBlock, size_t numberOfBlocks, void* settingsContainer));
    MOCK_METHOD4(writeToStreamReader, size_t(void* contents, size_t sizeOfBlock, size_t numberOfBlocks, void* streamReader));
    MOCK_METHOD4(writeToNothing, size_t(void* contents, size_t sizeOfBlock, size_t numberOfBlocks, void* doNotCast));
    MOCK_METHOD1(init, bool(CURLcode& curlCode));
    MOCK_METHOD0(destroy, void());
    MOCK_METHOD0(isGloballyInitialized, bool());
};

#endif
