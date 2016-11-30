enable_testing()

include_directories(inc)

file(GLOB_RECURSE TEST_SOURCES "src/*.cpp")

add_executable(test-runner test-runner.cpp ${TEST_SOURCES} src/Pollers/JsonTwitterStreamSettingsBuilderTest.cpp)
target_include_directories(test-runner BEFORE PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/test/inc"
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest/googletest/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/jsoncpp/include"
)
target_link_libraries(test-runner gtest gmock ${LIBRARIES} APIPOLLER)