
set(SOURCE_FILES
        APIPoller.cpp
        Pollers/TwitterPoller.cpp
        Signal/CloseCURLSignalHandler.cpp
        Signal/SignalManager.cpp
        Http/CurlHttpRequest.cpp
        Http/HttpRequest.cpp
        Http/HttpHeaders.cpp
        Encoders/IEncoder.cpp
        Encoders/UrlEncoder.cpp
        Pollers/Poller.cpp
        CurlHandler.cpp
        Pollers/TwitterStreamReader.cpp
        Http/HttpResponse.cpp
        Http/CurlHttpResponse.cpp
)

add_executable(${BINARY_NAME} ${SOURCE_FILES})
target_include_directories(${BINARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/inc")
target_link_libraries(${BINARY_NAME} ${LIBRARIES})