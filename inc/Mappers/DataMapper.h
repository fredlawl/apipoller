#ifndef APIPOOLER_DATAMAPPER_H
#define APIPOOLER_DATAMAPPER_H

#include "json/json.h"
#include "Pollers/Configuration/PollerSettings.h"

namespace APIPOLLER {
    template<typename Source, typename Destination>
    class DataMapper
    {
    public:
        virtual ~DataMapper() {}
        virtual Destination* from(const Source& json) const = 0;

    protected:
        DataMapper() {}
    };
}

#endif
