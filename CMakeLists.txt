cmake_minimum_required(VERSION 3.10)
project(game_of_life)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)

include_directories(Data)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(game_of_life
        main.cpp
        Data/Gamestate.cpp
        Data/Gamestate.h
        Display/Display.cpp
        Display/Display.h)

target_link_libraries(game_of_life ${SDL2_LIBRARIES})