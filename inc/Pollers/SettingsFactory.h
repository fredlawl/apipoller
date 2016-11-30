#ifndef APIPOOLER_SETTINGSFACTORY_H
#define APIPOOLER_SETTINGSFACTORY_H

#include "APIPoller.h"
#include "Configuration/BaseSettingsBuilder.h"

namespace APIPOLLER {

    template<typename SettingsProduct>
    class SettingsFactory {
    public:
        ~SettingsFactory() {}

        inline virtual BaseSettingsBuilder<SettingsProduct>* createSettingsBuilder() const;

    protected:
        SettingsFactory () {}
    };
}

#endif
