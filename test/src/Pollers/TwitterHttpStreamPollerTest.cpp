#include "gtest/gtest.h"
#include "Configuration/JsonConfiguration.h"
#include "Pollers/TwitterHttpStreamPoller.h"
#include "Mocks/HttpRequestMock.h"
#include "Mocks/CurlHandlerMock.h"

using ::testing::Return;

class TwitterHttpStreamPollerTest : public ::testing::Test
{
protected:
    APIPOLLER::TwitterHttpStreamPoller* poller = nullptr;

    virtual void SetUp() {
        APIPOLLER::JsonConfiguration someconfig;
        poller = new APIPOLLER::TwitterHttpStreamPoller();
    }

    virtual void TearDown() {
        delete poller;
    }
};


TEST_F(TwitterHttpStreamPollerTest, testFetch)
{
    HttpRequestMock httpRequestMock;

    poller->fetch();
}