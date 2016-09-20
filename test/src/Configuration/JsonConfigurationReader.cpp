#include "gtest/gtest.h"
#include "json/json.h"
#include "Configuration/JsonConfigurationReader.h"

class JsonConfigurationReaderTest : public ::testing::Test
{
protected:
    JsonConfigurationReader* configReader;

    virtual void SetUp()
    {
        Json::Reader jsonReader;
        configReader = new JsonConfigurationReader
    }

    virtual  void TearDown()
    {

    }
};

TEST_F(JsonConfigurationReader, testLoadFromFile)
{

}
