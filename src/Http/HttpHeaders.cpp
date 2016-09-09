#include "../../inc/Http/HttpHeaders.h"

std::ostream& operator<< (std::ostream& os, const APIPOLLER::HttpHeaders& httpHeaders)
{
    os << httpHeaders.toString() << std::endl;
    return os;
}

APIPOLLER::String APIPOLLER::HttpHeaders::toString() const
{
    String formattedHeaders;

    for (const auto& header : headers) {
        formattedHeaders.append("[").append(header.first).append("] => ").append(header.second);
    }

    return formattedHeaders;
}

