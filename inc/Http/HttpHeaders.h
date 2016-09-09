#ifndef APIPOOLER_HEADERS_H
#define APIPOOLER_HEADERS_H

#include "../APIPoller.h"

namespace APIPOLLER {
    class HttpHeaders;
}

class APIPOLLER::HttpHeaders
{
public:

    inline bool isEmpty() const;
    inline bool contains(const String& headerKey) const;
    inline String get(const String& headerKey) const;
    inline void insert(const String& headerKey, const String& headerValue);
    inline String remove(const String& headerKey);
    inline const unsigned long size() const;

    string_array_t getHeaderKeys() const;

    String toString() const;

    friend std::ostream& operator<< (std::ostream& os, const APIPOLLER::HttpHeaders& obj);

private:
    settings_t headers;

};

#endif