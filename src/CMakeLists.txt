
set(SOURCE_FILES
        TwitterPoller/HttpStream/TwitterHttpStreamPoller.cpp
        Signal/CloseCURLSignalHandler.cpp
        Signal/SignalManager.cpp
        Http/Curl/CurlHttpRequest.cpp
        Http/HttpRequest.cpp
        Http/HttpHeaders.cpp
        Encoders/UrlEncoder.cpp
        Pollers/Poller.cpp
        CurlHandler.cpp
        TwitterPoller/HttpStream/TwitterStreamReader.cpp
        Http/HttpResponse.cpp
        Http/Curl/CurlHttpResponse.cpp
        Loggers/STDLogger.cpp
        Configuration/JsonConfigurationReader.cpp
        TwitterPoller/HttpStream/Configuration/TwitterStreamSettingsBuilder.cpp Pollers/Configuration/PollerSettingsBuilder.cpp Pollers/PollerFactoryCreator.cpp Pollers/PollerSettingsFactoryCreator.cpp)

add_library(APIPOLLER ${SOURCE_FILES})
add_executable(${BINARY_NAME} APIPoller.cpp)
target_include_directories(APIPOLLER BEFORE PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/jsoncpp/include"
)
target_link_libraries(${BINARY_NAME} ${LIBRARIES} APIPOLLER)