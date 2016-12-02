#ifndef APIPOOLER_DATAMAPPER_H
#define APIPOOLER_DATAMAPPER_H

#include "json/json.h"
#include "Pollers/PollerConfiguration.h"

namespace APIPOLLER {
    template<typename Source, typename Desintation>
    class DataMapper
    {
    public:
        virtual ~DataMapper() {}
        virtual Desintation* from(const Source& json) const = 0;

    protected:
        DataMapper() {}
    };
}

#endif
