#ifndef APIPOOLER_TWITTERSTREAMREADER_H
#define APIPOOLER_TWITTERSTREAMREADER_H

#include "IStreamReader.h"

namespace APIPOLLER {
    class TwitterStreamReader;
}

class APIPOLLER::TwitterStreamReader : public IStreamReader
{
public:
    TwitterStreamReader() { }
    ~TwitterStreamReader() { }

    void readString(String* data);
};

#endif
