#include "gtest/gtest.h"
#include "json/json.h"
#include "Configuration/JsonConfigurationReader.h"

class JsonConfigurationReaderTest : public ::testing::Test
{
protected:
    APIPOLLER::JsonConfigurationReader* configReader;

    virtual void SetUp()
    {
        Json::Reader* jsonReader = new Json::Reader;
        configReader = new APIPOLLER::JsonConfigurationReader(jsonReader);
    }

    virtual  void TearDown()
    {
        delete configReader;
    }
};

TEST_F(JsonConfigurationReaderTest, testNonexistantFileReturnsNull)
{
    Json::Value* actual = configReader->loadFromFile("/this/file/does/not/exist");
    Json::Value* expected = nullptr;

    ASSERT_EQ(expected, actual);

    delete actual;
}