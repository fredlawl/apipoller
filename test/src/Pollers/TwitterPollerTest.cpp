#include "gtest/gtest.h"
#include "Pollers/TwitterPoller.h"
#include "Mocks/HttpRequestMock.h"
#include "Mocks/CurlHandlerMock.h"

using ::testing::Return;

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


TEST_F(TwitterPollerTest, testGetName)
{
    const char* actual = poller->getName().c_str();
    const char* expected = "Twitter API Poller";
    ASSERT_STREQ(expected, actual);
}


//TEST_F(TwitterPollerTest, testOpenConnection)
//{
//    bool result;
//    CurlHandlerMock instance;
//    CURLcode code;
//    EXPECT_CALL(instance, init(code)).WillOnce(Return(true));
//
//    result = poller->openConnection();
//    ASSERT_TRUE(result);
//}


//TEST_F(TwitterPollerTest, testCloseConnection)
//{
//    CurlHandlerMock instance;
//    EXPECT_CALL(instance, destroy()).Times(1);
//    poller->closeConnection();
//}


TEST_F(TwitterPollerTest, testFetch)
{
    EXPECT_CALL(*httpRequest, sendGetRequest("http://test.com")).Times(1);
    poller->fetch();
}