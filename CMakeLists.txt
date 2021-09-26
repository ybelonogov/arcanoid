cmake_minimum_required(VERSION 3.19)
project(arcanoid)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(gemes main.cpp Brick.cpp Brick.h BrickTypes.cpp BrickTypes.h check.cpp check.h game.cpp game.h)
target_link_libraries(gemes sfml-graphics sfml-audio)