#include "gtest/gtest.h"
#include "json/json.h"

class JsonCppAPITest : public ::testing::Test
{
protected:
    std::string pollerSettings;
    Json::Value parsedSettings;

    virtual void SetUp()
    {
        Json::Reader reader;
        pollerSettings = "{\"type\":\"twitter\",\"poller\":{\"stream\":false,\"reconnectAttempts\":3,\"url\":\"http:\\/\\/someurl.com\",\"method\":\"GET\",\"params\":{\"param1\":\"test\",\"param2\":\"test\",\"param3\":\"test\"}},\"connection\":{\"clientSecret\":\"abbk982ji3jlk2nas90d8f=\",\"userToken\":\"23@#ghyzxcvdfg%$Qachg\"}}";
        reader.parse(pollerSettings, parsedSettings);
    }

    virtual  void TearDown()
    {

    }
};


TEST_F(JsonCppAPITest, testAccessReturnsDefaultAsString)
{
    const char* actual = parsedSettings.get("lol", "noLolExists").asString().c_str();
    const char* expected = "noLolExists";
    ASSERT_STREQ(expected, actual);
}


TEST_F(JsonCppAPITest, testAccessReturnsAsString)
{
    const char* actual = parsedSettings.get("type", "default").asString().c_str();
    const char* expected = "twitter";
    ASSERT_STREQ(expected, actual);
}


TEST_F(JsonCppAPITest, testAccessOperatorSettingExists)
{
    const char* actual = parsedSettings["type"].asString().c_str();
    const char* expected = "twitter";
    ASSERT_STREQ(expected, actual);
}


TEST_F(JsonCppAPITest, testAccesssOperatorWithNoMatchingSetting)
{
    const char* actual = parsedSettings["nope"].asString().c_str();
    const char* expected = "";
    ASSERT_STREQ(expected, actual);
}


TEST_F(JsonCppAPITest, testNestedAccess)
{
    const char* actual = parsedSettings["poller"]["params"]["param3"].asString().c_str();
    const char* expected = "test";
    ASSERT_STREQ(expected, actual);
}


TEST_F(JsonCppAPITest, testBooleanAccess)
{
    bool actual = parsedSettings["poller"]["stream"].asBool();
    ASSERT_FALSE(actual);
}


TEST_F(JsonCppAPITest, testIntegerAccess)
{
    int actual = parsedSettings["poller"]["reconnectAttempts"].asInt();
    int expected = 3;
    ASSERT_EQ(expected, actual);
}