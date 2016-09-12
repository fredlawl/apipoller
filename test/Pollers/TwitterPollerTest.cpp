#include "gtest/gtest.h"
#include "../Mocks/HttpRequestMock.h"
#include "../../inc/Pollers/TwitterPoller.h"

class TwitterPollerTest : public ::testing::Test
{
protected:
    HttpRequestMock* httpRequest = nullptr;
    APIPOLLER::TwitterPoller* poller = nullptr;

    virtual void SetUp() {
        httpRequest = new HttpRequestMock();
        poller = new APIPOLLER::TwitterPoller(httpRequest);
    }

    virtual void TearDown() {
        delete httpRequest;
        delete poller;
    }
};