#ifndef APIPOOLER_ISETTINGSBUILDERDIRECTOR_H
#define APIPOOLER_ISETTINGSBUILDERDIRECTOR_H

namespace APIPOLLER
{
    template <typename SettingsProduct>
    class ISettingsBuilderDirector
    {
    public:
        virtual ~ISettingsBuilderDirector() {}
        virtual SettingsProduct* build() const = 0;

    protected:
        ISettingsBuilderDirector() {};
    };
}

#endif
