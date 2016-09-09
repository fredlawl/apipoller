#ifndef APIPOOLER_HEADERS_H
#define APIPOOLER_HEADERS_H

#include "../APIPoller.h"

namespace APIPOLLER {
    class HttpHeaders;
}

class APIPOLLER::HttpHeaders
{
public:
    inline const String& get(const String& headerKey) const;
    inline const String& insert(const String& headerKey, const String& headerValue);
    void remove(const String& headerKey);

    // @todo Need to add something for iteration ...

private:
    settings_t headers;

};

#endif