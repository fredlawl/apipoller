cmake_minimum_required(VERSION 3.5)
project(APIPooler)

set(BINARY_NAME "tweet")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "/usr/lib")
set(LIBRARIES "")

set(SOURCE_FILES
        src/APIPoller.cpp
        inc/APIPoller.h
        inc/GlobalIncludes.h

        src/Pollers/TwitterPoller.cpp
        inc/Pollers/TwitterPoller.h

        src/Signal/CloseCURLSignalHandler.cpp
        inc/Signal/ISignalHandler.h
        inc/Signal/CloseCURLSignalHandler.h

        src/Signal/SignalManager.cpp
        inc/Signal/SignalManager.h

        src/Http/CurlHttpRequest.cpp
        inc/Http/CurlHttpRequest.h
        inc/Http/HttpResponse.h

        src/Http/HttpRequest.cpp
        inc/Http/HttpRequest.h

        src/Encoders/IEncoder.cpp
        inc/Encoders/IEncoder.h

        src/Encoders/UrlEncoder.cpp
        inc/Encoders/UrlEncoder.h

        src/Pollers/Poller.cpp
        inc/Pollers/Poller.h

        src/CurlHandler.cpp
        inc/CurlHandler.h

        src/Pollers/TwitterStreamReader.cpp
        inc/Pollers/TwitterStreamReader.h
        inc/Pollers/IStreamReader.h src/Http/HttpResponse.cpp)
add_executable(${BINARY_NAME} ${SOURCE_FILES})


#FIND_PATH(LIBRABBITMQ_INCLUDE_DIRS NAMES amqp.h)
#MARK_AS_ADVANCED(LIBRABBITMQ_INCLUDE_DIR)
#
#FIND_LIBRARY(LIBRABBITMQ_LIBRARY NAMES rabbitmq)
#MARK_AS_ADVANCED(LIBRABBITMQ_LIBRARY)
#
#INCLUDE(FindPackageHandleStandardArgs)
#FIND_PACKAGE_HANDLE_STANDARD_ARGS(LIBRABBITMQ DEFAULT_MSG LIBRABBITMQ_LIBRARY LIBRABBITMQ_INCLUDE_DIR)
#
##find_library(RABBITMQ NAMES rabbitmq REQUIRED)
#if (LIBRABBITMQ_FOUND)
#    include_directories(${LIBRABBITMQ_INCLUDE_DIRS})
#    set(LIBRARIES ${LIBRARIES} ${LIBRABBITMQ_LIBRARY})
#else(LIBRABBITMQ_FOUND)
#    message(FATAL_ERROR "Could not find the RabbitMQ library and development files.")
#endif(LIBRABBITMQ_FOUND)
set(LIBRARIES ${LIBRARIES} rabbitmq)

FIND_PATH(CURL_INCLUDE_DIR NAMES curl/curl.h)
MARK_AS_ADVANCED(CURL_INCLUDE_DIR)

FIND_LIBRARY(CURL_LIBRARY NAMES curl)
MARK_AS_ADVANCED(CURL_LIBRARY)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(CURL DEFAULT_MSG CURL_LIBRARY CURL_INCLUDE_DIR)

if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIR})
    set(LIBRARIES ${LIBRARIES} ${CURL_LIBRARY})
else(CURL_FOUND)
    message(FATAL_ERROR "Could not find the CURL library and development files.")
endif(CURL_FOUND)

target_link_libraries(${BINARY_NAME} ${LIBRARIES})