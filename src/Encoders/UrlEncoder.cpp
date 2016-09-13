
#include "Encoders/UrlEncoder.h"

const APIPOLLER::characterset_t APIPOLLER::UrlEncoder::SAFE_CHARACTERS = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '-', '.', '_', '~'
};


APIPOLLER::String APIPOLLER::UrlEncoder::encode(const APIPOLLER::String& rawString) const
{
    std::vector<char> encodedStringVector(rawString.size());
    encodedStringVector.clear();

    const char* rawCharacterArray = rawString.c_str();
    size_t stringLength = rawString.length();
    size_t i = 0;
    unsigned char hex1, hex2;
    char checkedCharacter;

    for (; i < stringLength; ++i) {
        checkedCharacter = rawCharacterArray[i];
        if (isCharacterSafe(rawCharacterArray[i])) {
            encodedStringVector.push_back(checkedCharacter);
            continue;
        }

        hexchar(checkedCharacter, hex1, hex2);
        encodedStringVector.push_back('%');
        encodedStringVector.push_back(hex1);
        encodedStringVector.push_back(hex2);
    }

    return String(encodedStringVector.cbegin(), encodedStringVector.cend());
}


void APIPOLLER::UrlEncoder::hexchar(unsigned char checkedCharacter, unsigned char& hex1, unsigned char& hex2) const
{
    hex1 = checkedCharacter / 16;
    hex2 = checkedCharacter % 16;
    hex1 += hex1 <= 9 ? '0' : 'A' - 10;
    hex2 += hex2 <= 9 ? '0' : 'A' - 10;
}


APIPOLLER::String APIPOLLER::UrlEncoder::decode(const String& encodedString) const
{
    return "";
}


bool APIPOLLER::UrlEncoder::isCharacterSafe(char character) const
{
    characterset_t::const_iterator iterator = SAFE_CHARACTERS.find(character);
    return (iterator != SAFE_CHARACTERS.cend());
}





