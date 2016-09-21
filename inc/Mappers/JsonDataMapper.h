#ifndef APIPOOLER_DATAMAPPER_H
#define APIPOOLER_DATAMAPPER_H

#include "json/json.h"
#include "Pollers/PollerConfiguration.h"

namespace APIPOLLER {
    template<typename Configuration>
    class JsonDataMapper
    {
    public:
        virtual ~JsonDataMapper() {}
        virtual Configuration from(const Json::Value& json) const = 0;

    protected:
        JsonDataMapper() {}
    };
}

#endif
