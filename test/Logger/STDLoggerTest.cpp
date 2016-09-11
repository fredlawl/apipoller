#include "gtest/gtest.h"
#include "../../inc/Loggers/STDLogger.h"

class STDLoggerTest : public ::testing::Test
{
protected:
    APIPOLLER::ILogger* logger = nullptr;

    virtual void SetUp() {
        logger = new APIPOLLER::STDLogger();
    }

    virtual void TearDown() {
        delete logger;
    }
};


TEST_F(STDLoggerTest, testOutputToSTDOUT)
{
    testing::internal::CaptureStdout();
    logger->logMessage("This works");

    const char* expectedCString = "This works\n";
    const char* actualCString = testing::internal::GetCapturedStdout().c_str();

    ASSERT_STREQ(expectedCString, actualCString);
}


TEST_F(STDLoggerTest, testOutputToSTDERR)
{
    testing::internal::CaptureStderr();
    logger->logError("This is an error");

    const char* expected = "This is an error\n";
    const char* actual = testing::internal::GetCapturedStderr().c_str();

    ASSERT_STREQ(expected, actual);
}