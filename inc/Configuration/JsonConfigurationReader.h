#ifndef APIPOOLER_JSONCONFIGURATIONREADER_H
#define APIPOOLER_JSONCONFIGURATIONREADER_H

#include "APIPoller.h"
#include "json/json.h"

namespace APIPOLLER {
    class JsonConfigurationReader;
}

class APIPOLLER::JsonConfigurationReader
{
public:
    JsonConfigurationReader(Json::Reader* jsonReader) : reader(jsonReader) {}
    ~JsonConfigurationReader() {};

    Json::Value* loadFromFile(const String& path) const;

private:
    Json::Reader* reader;
};

#endif
