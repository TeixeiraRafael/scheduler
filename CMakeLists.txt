cmake_minimum_required(VERSION 3.17)
project(scheduler)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

file(
        GLOB
        SOURCES
        "src/*.cpp"
        "include/*.h"
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} ncurses pthread)