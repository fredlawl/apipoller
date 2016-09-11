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


TEST_F(STDLoggerTest, testOutputToSTDOUT) {
    testing::internal::CaptureStdout();

    logger->logMessage("This works");

    std::string output = testing::internal::GetCapturedStdout();
    const char* expectedCString = "This works\n";
    const char* actualCString = output.c_str();

    ASSERT_STREQ(expectedCString, actualCString);
}