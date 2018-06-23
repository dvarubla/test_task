cmake_minimum_required(VERSION 3.11)
project(test_task)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EXTRA_CMAKE_CXX_FLAGS} -W -Wall -Wextra -Werror -pedantic")

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    message("Adding sanitizer flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=undefined -fsanitize=leak")
endif()

add_subdirectory("googletest/googlemock" EXCLUDE_FROM_ALL)
add_subdirectory(src)
add_subdirectory(tests)