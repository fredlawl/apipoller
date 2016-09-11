#include "../../inc/Loggers/STDLogger.h"

void APIPOLLER::STDLogger::logMessage(const APIPOLLER::String& message) const
{
    std::cout << message << std::endl;
}


void APIPOLLER::STDLogger::logWarning(const String& message) const
{

}


void APIPOLLER::STDLogger::logError(const String& message) const
{
    std::cerr << message << std::endl;
}





