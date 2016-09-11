#include "gtest/gtest.h"

class LoggerTest : public ::testing::Test
{
protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }
};


TEST(LoggerTest, testForTest) {
    ASSERT_FALSE(false);
}