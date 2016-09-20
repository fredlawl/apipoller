#include "gtest/gtest.h"
#include "TwitterPoller/HttpStream/TwitterHttpStreamPoller.h"
#include "Mocks/HttpRequestMock.h"
#include "Mocks/CurlHandlerMock.h"

using ::testing::Return;

class TwitterHttpStreamPollerTest : public ::testing::Test
{
protected:
    APIPOLLER::TwitterHttpStreamPoller* poller = nullptr;

    virtual void SetUp() {
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