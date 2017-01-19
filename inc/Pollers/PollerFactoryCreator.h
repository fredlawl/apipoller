#ifndef APIPOOLER_POLLERCREATOR_H
#define APIPOOLER_POLLERCREATOR_H

namespace APIPOLLER {
    class PollerFactoryCreator;
	class IPollerFactory;
	class Poller;
}

class APIPOLLER::PollerFactoryCreator
{
public:
    IPollerFactory* getFactory(const String& factoryType) const;
    Poller* getType(IPollerFactory* factory, const String& pollerType) const;
};

#endif
