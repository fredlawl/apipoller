#include "Configuration/JsonConfiguration.h"

APIPOLLER::Configuration* APIPOLLER::JsonConfiguration::get(const String& key) const
{
    return new JsonConfiguration();
}


void APIPOLLER::JsonConfiguration::set(const String& key, const String& value)
{

}



