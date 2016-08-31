#include "../../inc/Signal/CloseCURLSignalHandler.h"
#include <iostream>

void APIPOLLER::CloseCURLSignalHandler::handle(int signum)
{
    std::cout << "This was killed!" << std::endl;
    curl_global_cleanup();
    exit(signum);
}