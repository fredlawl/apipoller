#ifndef APIPOOLER_ISETTINGSBUILDER_H
#define APIPOOLER_ISETTINGSBUILDER_H

namespace APIPOLLER
{
    template <typename SettingsProduct>
    class ISettingsBuilder
    {
    public:
        virtual ~ISettingsBuilder() {}
        virtual SettingsProduct* build() = 0;

    protected:
        ISettingsBuilder() {};
    };
}

#endif
