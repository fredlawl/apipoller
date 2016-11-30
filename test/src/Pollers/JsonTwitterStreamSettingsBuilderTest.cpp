#include <TwitterPoller/HttpStream/Configuration/TwitterHttpStreamSettings.h>
#include <Http/Configuration/HttpRequestSettings.h>
#include "gtest/gtest.h"
#include "json/json.h"
#include "Configuration/JsonConfigurationReader.h"
#include "TwitterPoller/HttpStream/Configuration/JsonTwitterStreamSettingsBuilder.h"

class JsonTwitterStreamSettingsBuilderTest : public ::testing::Test
{
protected:
    APIPOLLER::JsonConfigurationReader* configReader;
    APIPOLLER::JsonTwitterStreamSettingsBuilder* builder;

    virtual void SetUp()
    {
        Json::Reader* jsonReader = new Json::Reader;
        configReader = new APIPOLLER::JsonConfigurationReader(jsonReader);
    }

    virtual void TearDown()
    {
        delete configReader;
        delete builder;
    }
};


TEST_F(JsonTwitterStreamSettingsBuilderTest, testBuilder)
{
    using namespace APIPOLLER;
    Json::Value* config = configReader->loadFromFile("../test/files/testSettings.json");
    builder = new JsonTwitterStreamSettingsBuilder(config);

    TwitterHttpStreamSettings* actual = builder->withHttpSettings()->build();

    TwitterHttpStreamSettings expected;
    expected.requestConfiguration->url = "http://httpbin.org/get";
    expected.requestConfiguration->method = HttpRequest::Method::GET;

    settings_t settings;
//    expected.requestConfiguration->parameters = settings;
//    expected.requestConfiguration->parameters.insert(std::make_pair<String, String>("show_env", "1"));

    delete builder;
    delete actual;
    builder = nullptr;
}