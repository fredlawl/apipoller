cmake_minimum_required(VERSION 3.5)
project(APIPooler)

set(BINARY_NAME "tweet")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "/usr/lib")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(LIBRARIES "")

include_directories(inc)

set(LIBRARIES ${LIBRARIES} rabbitmq)

find_package(LibCURL REQUIRED)
if (LIBCURL_FOUND)
    include_directories(${LIBCURL_INCLUDE_DIR})
    set(LIBRARIES ${LIBRARIES} ${LIBCURL_LIBRARY})
else(LIBCURL_FOUND)
    message(FATAL_ERROR "Could not find the CURL library and development files.")
endif(LIBCURL_FOUND)

add_subdirectory(src)
add_subdirectory(lib/googletest)
add_subdirectory(test)