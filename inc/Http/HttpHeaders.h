#ifndef APIPOOLER_HEADERS_H
#define APIPOOLER_HEADERS_H

#include "../APIPoller.h"

namespace APIPOLLER {
    class HttpHeaders;
}

class APIPOLLER::HttpHeaders
{
public:
    typedef settings_t::iterator iterator;
    typedef settings_t::const_iterator const_iterator;

    inline const String& get(const String& headerKey) const;
    inline void insert(const String& headerKey, const String& headerValue);
    inline void remove(const String& headerKey);

    const string_array_t& getHeaderKeys() const;

    inline iterator begin() { return headers.begin(); }
    inline iterator end() { return headers.end(); }

    inline const_iterator cbegin() { return headers.cbegin(); }
    inline const_iterator cend() { return headers.cend(); }

    // @todo Need to add something for iteration ...

private:
    settings_t headers;

};

#endif