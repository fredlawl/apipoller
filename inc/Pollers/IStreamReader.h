#ifndef APIPOOLER_ISTREAMREADER_H
#define APIPOOLER_ISTREAMREADER_H

#include "./../APIPoller.h"

namespace APIPOLLER {
    class IStreamReader;

    // hack, APIPoller.h isn't being pulled in? Needs further investigation
    typedef std::string String;
}

class APIPOLLER::IStreamReader
{
public:
    virtual void readString(const String& data) = 0;
    virtual ~IStreamReader() { }

protected:
    IStreamReader() { };
};

#endif