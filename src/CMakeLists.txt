
set(SOURCE_FILES
        Pollers/TwitterPoller.cpp
        Signal/CloseCURLSignalHandler.cpp
        Signal/SignalManager.cpp
        Http/CurlHttpRequest.cpp
        Http/HttpRequest.cpp
        Http/HttpHeaders.cpp
        Encoders/UrlEncoder.cpp
        Pollers/Poller.cpp
        CurlHandler.cpp
        Pollers/TwitterStreamReader.cpp
        Http/HttpResponse.cpp
        Http/CurlHttpResponse.cpp
        Loggers/STDLogger.cpp Configuration/JsonConfigurationManager.cpp)

add_library(APIPOLLER ${SOURCE_FILES})
add_executable(${BINARY_NAME} APIPoller.cpp)
target_include_directories(APIPOLLER BEFORE PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/jsoncpp/include"
)
target_link_libraries(${BINARY_NAME} ${LIBRARIES} APIPOLLER)