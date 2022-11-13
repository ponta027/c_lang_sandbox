project(project_name)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_TEENY 1)
set(PACKAGE_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_TEENY}")

cmake_minimum_required(VERSION 2.8)

add_executable( server src/server.c src/mqueue_util.c)
add_executable( client src/client.c src/mqueue_util.c)


target_include_directories( server PUBLIC include)
target_include_directories( client PUBLIC include)




