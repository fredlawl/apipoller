#ifndef APIPOOLER_ISTREAMREADER_H
#define APIPOOLER_ISTREAMREADER_H

#include "../APIPoller.h"

namespace APIPOLLER {
    class IStreamReader;
}

class APIPOLLER::IStreamReader
{
public:
    virtual void readString(const String& data) = 0;

    virtual ~IStreamReader() { }

private:
    IStreamReader() { };
    IStreamReader& operator=(const IStreamReader&) = delete;
    IStreamReader(const IStreamReader&) = delete;
};

#endif
