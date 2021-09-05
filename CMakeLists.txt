cmake_minimum_required(VERSION 3.19)
project(arcanoid)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(gemes main.cpp brick.cpp brick.h brick_types.cpp brick_types.h check.cpp check.h)
target_link_libraries(gemes sfml-graphics sfml-audio)