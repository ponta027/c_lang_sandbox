project(sample)

set(1_VERSION_MAJOR 0)
set(1_VERSION_MINOR 0)
set(1_VERSION_TEENY 1)
set(PACKAGE_VERSION "${1_VERSION_MAJOR}.${1_VERSION_MINOR}.${1_VERSION_TEENY}")

cmake_minimum_required(VERSION 3.5)
include("option.cmake")


add_subdirectory(hello)


if(TRACE)
add_executable( sample hook.c main.c)
target_link_libraries( sample dl dwarf hello)
target_link_options(sample PRIVATE -rdynamic)
else()
add_executable( sample  main.c)
target_link_libraries( sample hello)
endif()

