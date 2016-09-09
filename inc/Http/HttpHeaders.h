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
    inline void insert(const String& headerKey, const String& headerValue);
    inline void remove(const String& headerKey);

    const string_array_t& getHeaderKeys() const;

    // @todo Need to add something for iteration ...

private:
    settings_t headers;

};

#endif