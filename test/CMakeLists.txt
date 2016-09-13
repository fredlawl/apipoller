enable_testing()

include_directories(inc)

file(GLOB_RECURSE TEST_SOURCES "src/*.cpp")

add_executable(test-runner test-runner.cpp ${TEST_SOURCES})
target_include_directories(test-runner PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/test/inc")
target_include_directories(test-runner PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest/googletest/include")
target_link_libraries(test-runner gtest gmock ${LIBRARIES} APIPOLLER)