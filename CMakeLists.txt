cmake_minimum_required(VERSION 3.17)
project(AchtungKurve)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "libs/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "libs/SFML-2.5.1/lib")
set(SFML_DIR "libs/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(AchtungKurve main.cpp src/menu/window.cpp src/menu/options.cpp src/menu/config.cpp include/menu/config.h src/menu/player.cpp include/menu/player.h include/menu/window.h src/game/snake.cpp src/game/snake.h src/game/GameWindow.cpp src/game/GameWindow.h)
target_link_libraries (AchtungKurve sfml-graphics sfml-window sfml-system)