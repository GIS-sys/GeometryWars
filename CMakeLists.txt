cmake_minimum_required(VERSION 3.5)
project(game)

set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")
find_package(X11 REQUIRED)
file(GLOB_RECURSE SRC geometry_wars/*.cpp)

add_executable(game ${SRC})
target_link_libraries(game m X11)
