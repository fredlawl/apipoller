#ifndef APIPOLLER_IENCODER_H
#define APIPOLLER_IENCODER_H

#include "../APIPoller.h"

namespace APIPOLLER {
    class IEncoder;
}

class APIPOLLER::IEncoder
{
public:
    virtual ~IEncoder() { }
    virtual String encode(const String& string) const = 0;
    virtual String decode(const String& string) const = 0;
};

#endif
