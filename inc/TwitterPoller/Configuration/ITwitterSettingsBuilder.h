#ifndef APIPOOLER_ITWITTERSETTINGSBUILDER_H
#define APIPOOLER_ITWITTERSETTINGSBUILDER_H

namespace APIPOLLER {
    template<class Builder>
    class ITwitterSettingsBuilder {
    public:
        virtual ~ITwitterSettingsBuilder() { }

        virtual Builder* withTwitterSettings() = 0;

    protected:
        ITwitterSettingsBuilder() { }
    };
}

#endif
