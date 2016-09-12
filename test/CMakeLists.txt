enable_testing()

file(GLOB_RECURSE TEST_SOURCES "*.cpp")
file(GLOB_RECURSE TEST_HEADERS "*.h")

add_executable(test-runner test-runner.cpp ${TEST_SOURCES} ${TEST_HEADERS})
target_include_directories(test-runner PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest/googletest/include")
target_link_libraries(test-runner gtest gmock APIPOLLER)