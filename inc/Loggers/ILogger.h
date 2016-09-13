#ifndef APIPOOLER_ILOGGER_H
#define APIPOOLER_ILOGGER_H

#include "APIPoller.h"

namespace APIPOLLER {
    class ILogger;
}

class APIPOLLER::ILogger
{
public:
    virtual ~ILogger() { }

    virtual void logMessage(const String& message) const = 0;
    virtual void logWarning(const String& message) const = 0;
    virtual void logError(const String& message) const = 0;

protected:
    ILogger() {}
};

#endif
