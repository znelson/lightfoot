cmake_minimum_required(VERSION 3.28)
project(lightfoot)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR})
file(GLOB SOURCES_APP "app/*.cpp")
file(GLOB SOURCES_DEBUG "debug/*.cpp")

add_executable(lightfoot main.cpp ${SOURCES_APP} ${SOURCES_DEBUG}
        debug/PixelFormat.cpp
        debug/PixelFormat.h)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
