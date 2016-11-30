#ifndef APIPOOLER_BASESETTINGSBUILDER_H
#define APIPOOLER_BASESETTINGSBUILDER_H

namespace APIPOLLER
{
    template <typename SettingsProduct>
    class BaseSettingsBuilder
    {
    public:
        virtual ~BaseSettingsBuilder() {}
        virtual SettingsProduct* build() = 0;

    protected:
        BaseSettingsBuilder() {};
    };
}

#endif
