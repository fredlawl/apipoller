#include "gtest/gtest.h"
#include "../Mocks/HttpRequestMock.h"
#include "../../inc/Pollers/TwitterPoller.h"

class TwitterPollerTest : public ::testing::Test
{
protected:
    HttpRequestMock* httpRequest = nullptr;

    virtual void SetUp() {
        httpRequest = new HttpRequestMock();
    }

    virtual void TearDown() {
        delete httpRequest;
    }
};


TEST_F(TwitterPollerTest, testTwitterPollerAcceptsHttpResponse)
{
    APIPOLLER::TwitterPoller poller(httpRequest);
    ASSERT_TRUE(true);
}