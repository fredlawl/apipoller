#ifndef APIPOOLER_UTILITY_H
#define APIPOOLER_UTILITY_H

#include "APIPoller.h"

namespace APIPOLLER {
    class Utility;
}

class APIPOLLER::Utility
{
public:

    inline static string_array_t splitAtDelimiterOnce(const String& stringToParse, char delim)
    {
        size_t firstFoundDelim = stringToParse.find_first_of(delim);
        string_array_t container;

        if (firstFoundDelim == String::npos) {
            return container;
        }

        String key = stringToParse.substr(0, firstFoundDelim);
        String value = stringToParse.substr(firstFoundDelim + 1, stringToParse.size());

        trim_inplace(key);
        trim_inplace(value);

        container.push_back(key);
        container.push_back(value);
        return container;
    }


    /*
     * The following functions were found in the link provided.
     *
     * @see http://stackoverflow.com/a/20023250/6018969
     */
    inline static const char* trim_start(const char* str)
    {
        while (memchr(" \t\n\r", *str, 4))  ++str;
        return str;
    }


    inline static const char* trim_end(const char* end)
    {
        while (memchr(" \t\n\r", end[-1], 4)) --end;
        return end;
    }


    inline static std::string trim(const char* buffer, int len)
    {
        return std::string(trim_start(buffer), trim_end(buffer + len));
    }


    inline static void trim_inplace(std::string& str)
    {
        str.assign(trim_start(str.c_str()),
                   trim_end(str.c_str() + str.length()));
    }

};

#endif
