#ifndef APIPOOLER_STDLOGGER_H
#define APIPOOLER_STDLOGGER_H

#include "ILogger.h"

namespace APIPOLLER {
    class STDLogger;
}

class APIPOLLER::STDLogger : public ILogger
{
public:
    void logMessage(const String& message) const;
    void logWarning(const String& message) const;
    void logError(const String& message) const;
};

#endif
