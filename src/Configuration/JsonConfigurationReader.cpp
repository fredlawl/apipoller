#include "Configuration/JsonConfigurationReader.h"

Json::Value* APIPOLLER::JsonConfigurationReader::loadFromFile(const APIPOLLER::String& path) const
{
    Json::Value* configuration = new Json::Value;
    std::ifstream fileStream(path, std::ifstream::binary);
    if (!fileStream.good()) {
        delete configuration;
        return nullptr;
    }

    bool parsed = reader->parse(fileStream, *configuration);
    if (!parsed) {
        delete configuration;
        return nullptr;
    }

    return configuration;
}

