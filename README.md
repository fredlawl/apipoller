# Twitter Stream API Listener
A sample application to listen on Twitters Stream API service.

## Goal
* Connect and listen for data from the Twitter Stream API
* Minimally parse data (json/plaintext)
* Shove data into a RabbitMQ queue.

## Dependencies
* Linux/Unix machine (Windows not supported)
* CMAKE v3.5+
* C++14 compiler
* [libcurl](https://curl.haxx.se/libcurl/)
* [rabbitmq-c](https://github.com/alanxz/rabbitmq-c)