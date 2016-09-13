#include "gtest/gtest.h"
#include "Pollers/TwitterCredentials.h"

class TwitterCredentialsTest : public ::testing::Test
{
protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }
};


TEST(TwitterCredentialsTest, testClassExists)
{
    using namespace APIPOLLER;
    TwitterCredentials creds;
    ASSERT_TRUE(true);
}