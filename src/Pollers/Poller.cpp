#include "../../inc/Pollers/Poller.h"

bool APIPOLLER::Poller::run()
{
    if (!openConnection()) {
        std::cerr << "Unable to establish a connection for " << getName() << std::endl;
        return false;
    }

    loop();

    closeConnection();

    return false;
}

void APIPOLLER::Poller::loop() {
    while (true) {
        if (!testConnection()) {
            if (!reopenConnection())
                break;
        }

        fetch();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

