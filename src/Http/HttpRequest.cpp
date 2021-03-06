#include "Http/HttpRequest.h"
#include "Encoders/IEncoder.h"


APIPOLLER::settings_t* APIPOLLER::HttpRequest::encodeParameters() const
{
    settings_t* queryParameters = nullptr;
    String encodedParameter;
    String encodedKey;

    if (encoder == nullptr || parameters.empty())
        return nullptr;

    queryParameters = new settings_t;
    for (auto parameter : parameters) {
        encodedKey = encoder->encode(parameter.first);
        encodedParameter = encoder->encode(parameter.second);
        queryParameters->emplace(encodedKey, encodedParameter);
    }

    return queryParameters;
}


APIPOLLER::String APIPOLLER::HttpRequest::buildQueryString() const
{
    String queryString = "";
    size_t counter = 0;
    settings_t* encodedParameters = ((settings_t*) &parameters);

    if (hasEncoder()) {
        encodedParameters = encodeParameters();
    }

    for (auto parameter : *encodedParameters) {
        if (counter > 0) {
            queryString.append("&", 1);
        }

        queryString.append(parameter.first);
        queryString.append("=", 1);
        queryString.append(parameter.second);
        ++counter;
    }

    return queryString;
}


