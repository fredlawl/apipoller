#ifndef APIPOOLER_TWITTERSTREAMREADER_H
#define APIPOOLER_TWITTERSTREAMREADER_H

#include "Pollers/IStreamReader.h"

namespace APIPOLLER {
    class TwitterStreamReader;
}

class APIPOLLER::TwitterStreamReader : public IStreamReader
{
public:
    TwitterStreamReader() { }
    ~TwitterStreamReader() { }

    void readString(const String& data);
};

#endif
