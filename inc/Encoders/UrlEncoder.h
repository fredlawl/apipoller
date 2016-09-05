#ifndef APIPOLLER_URLENCODER_H
#define APIPOLLER_URLENCODER_H

#include "../Encoders/IEncoder.h"

namespace APIPOLLER {
    class UrlEncoder;
}

/**
 * This encoder class follows the spec as defined in the Pollers Streaming API docs.
 * Encoding should be compliant with the RFC3986 spec.
 *
 * @see https://dev.twitter.com/oauth/overview/percent-encoding-parameters
 */
class APIPOLLER::UrlEncoder : public IEncoder
{
public:
    UrlEncoder() { }
    ~UrlEncoder() { }

    /**
     * @see https://gist.github.com/lite3/1197e5c24eb9ec93d771
     */
    String encode(const String& rawString) const;

    /**
     * Not implemented
     */
    String decode(const String& encodedString) const;

    /**
     * @see https://gist.github.com/lite3/1197e5c24eb9ec93d771
     */
    void hexchar(unsigned char checkedCharacter, unsigned char& hex1, unsigned char& hex2) const;

    /**
     * Checks if a character is contained within SAFE_CHARACTERS
     */
    bool isCharacterSafe(char character) const;

private:
    static const characterset_t SAFE_CHARACTERS;

};

#endif
