#include "../../inc/Http/HttpHeaders.h"

std::ostream& APIPOLLER::operator<< (std::ostream& os, const APIPOLLER::HttpHeaders& httpHeaders)
{
    os << httpHeaders.toString() << std::endl;
    return os;
}


APIPOLLER::String APIPOLLER::HttpHeaders::get(const String& headerKey) const
{
    return (contains(headerKey)) ? headers.at(headerKey) : "";
}


APIPOLLER::String APIPOLLER::HttpHeaders::toString() const
{
    String formattedHeaders;

    for (const auto& header : headers) {
        formattedHeaders.append("[").append(header.first).append("] => ").append(header.second).append("\n");
    }

    return formattedHeaders;
}


bool APIPOLLER::HttpHeaders::contains(const String& headerKey) const
{
    settings_t::const_iterator it = headers.find(headerKey);
    return (it != headers.cend());
}


void APIPOLLER::HttpHeaders::insert(const String& headerKey, const String& headerValue)
{
    headers.emplace(headerKey, headerValue);
}


APIPOLLER::String APIPOLLER::HttpHeaders::remove(const String& headerKey)
{
    String currentValue;

    if (contains(headerKey))
        currentValue = get(headerKey);

    headers.erase(headerKey);
    return currentValue;
}


bool APIPOLLER::HttpHeaders::isEmpty() const
{
    return headers.empty();
}


APIPOLLER::string_array_t APIPOLLER::HttpHeaders::getHeaderKeys() const
{
    string_array_t keys;
    for (const auto& header : headers) {
        keys.push_back(header.first);
    }

    return keys;
}


const unsigned long APIPOLLER::HttpHeaders::size() const
{
    return headers.size();
}



