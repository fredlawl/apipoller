#ifndef APIPOOLER_POLLERFACTORYMAPPER_H
#define APIPOOLER_POLLERFACTORYMAPPER_H

#include "APIPoller.h"

namespace APIPOLLER {

    template<class F>
    F* fCreate()
    {
        return new F();
    }

    template<class T>
    class FactoryRegistry {
    public:
        FactoryRegistry() {}
        ~FactoryRegistry() {}

        template<class F>
        void registerFactory(const String& className)
        {
            F* construct = (F*) &fCreate<F>;
//            std::pair<String, factory_constructor_t> special;
//            auto special = std::make_pair(className, *construct);
            constructors.emplace(className, construct);
        }

        T* get(const String &className)
        {
            return constructors.at(className);
        }

    private:
        typedef T* (*factory_constructor_t)();
        typedef std::unordered_map<String, factory_constructor_t> Factories;
        Factories constructors;
    };
}
#endif
