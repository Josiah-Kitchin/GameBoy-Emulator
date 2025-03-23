
cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Prod)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG_BUILD)
endif()

project(gameboy_emu CXX)

file(GLOB_RECURSE SOURCES "src/*.cc")

add_executable(gameboy ${SOURCES})

include_directories(./include)

target_compile_options(gameboy PRIVATE -Wall -Wextra -O3)
