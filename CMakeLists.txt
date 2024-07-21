cmake_minimum_required(VERSION 3.5)
project(game)

# I have no idea what this is but ok
set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")

# add X11 for graphics
find_package(X11 REQUIRED)

# find all cpp files recursively to build game
file(GLOB_RECURSE SRC geometry_wars/*.cpp)

# add base path to cmake for absolute header paths
SET(BASEPATH "${CMAKE_SOURCE_DIR}")
INCLUDE_DIRECTORIES("${BASEPATH}")

# build and link
add_executable(game ${SRC})
target_link_libraries(game m X11)
