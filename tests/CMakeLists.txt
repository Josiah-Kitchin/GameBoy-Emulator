cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)

project(test_gameboy CXX)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/../src/*.cc")
list(FILTER SOURCES EXCLUDE REGEX ".*/main\\.cc$")

file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")


include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_executable(test_gameboy ${SOURCES} ${TEST_SOURCES})

target_include_directories(test_gameboy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_link_libraries(
        test_gameboy PRIVATE 
        gtest 
        gtest_main
    )

target_compile_options(test_gameboy PRIVATE -Wall -Wextra -g)

