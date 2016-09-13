#include "gtest/gtest.h"
#include "Pollers/TwitterPoller.h"
#include "Mocks/HttpRequestMock.h"
#include "Mocks/CurlHandlerMock.h"

using ::testing::Return;

class TwitterPollerTest : public ::testing::Test
{
protected:
    APIPOLLER::TwitterPoller* poller = nullptr;

    virtual void SetUp() {
        poller = new APIPOLLER::TwitterPoller();
    }

    virtual void TearDown() {
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

    poller->fetch();
}