#ifndef APIPOOLER_HTTP_H
#define APIPOOLER_HTTP_H

#include "../APIPoller.h"

namespace APIPOLLER {
    typedef struct {
        String version;
        long statusCode;
        String message;
    } HTTP;
}

#endif
