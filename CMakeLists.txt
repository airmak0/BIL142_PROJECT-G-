cmake_minimum_required(VERSION 3.27)
project(CosmicVoyageR)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)

add_executable(CosmicVoyageR
        main.cpp
        src/ship.cpp
        src/normal_ship.cpp
        src/quick_ship.cpp
        src/strong_ship.cpp
        src/event.cpp
        src/asteroid_belt.cpp
        src/abandoned_planet.cpp
        src/space_pirates.cpp)
