#ifndef APIPOLLER_APIPOLLER_H
#define APIPOLLER_APIPOLLER_H

#include "GlobalIncludes.h"

namespace APIPOLLER {
    typedef std::string String;
    typedef std::chrono::system_clock::time_point timepoint_t;
    typedef std::unordered_map<String, String> settings_t;
    typedef std::unordered_set<char> characterset_t;
    typedef std::vector<String> string_array_t;
}

#endif
