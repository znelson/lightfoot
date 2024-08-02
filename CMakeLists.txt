cmake_minimum_required(VERSION 3.28)
project(lightfoot)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR})
file(GLOB SOURCES_APP "app/*.cpp")
file(GLOB SOURCES_DEBUG "debug/*.cpp")
file(GLOB SOURCES_THIRD_PARTY "third_party/*.c")

add_executable(lightfoot main.cpp ${SOURCES_APP} ${SOURCES_DEBUG} ${SOURCES_THIRD_PARTY})

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(SDL2::SDL2 SDL2_ttf::SDL2_ttf)
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2 SDL2_ttf::SDL2_ttf)

add_custom_command(
        TARGET lightfoot POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/res/FiraCode-Regular.ttf
        ${CMAKE_BINARY_DIR}/res/FiraCode-Regular.ttf)
