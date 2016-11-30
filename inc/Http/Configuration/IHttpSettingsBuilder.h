
#ifndef APIPOOLER_IHTTPSETTINGSBUILDER_H
#define APIPOOLER_IHTTPSETTINGSBUILDER_H

namespace APIPOLLER {
    template<class Builder>
    class IHttpSettingsBuilder {
    public:
        virtual ~IHttpSettingsBuilder() { }

        virtual Builder* withHttpSettings() = 0;

    protected:
        IHttpSettingsBuilder() { }
    };
}

#endif
