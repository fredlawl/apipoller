#include "../../inc/Http/HttpRequest.h"
#include "../../inc/Encoders/IEncoder.h"


APIPOLLER::settings_t *APIPOLLER::HttpRequest::encodeParameters() const
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
