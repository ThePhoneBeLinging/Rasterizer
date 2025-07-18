cmake_minimum_required(VERSION 3.31)
project(Rasterization)

set(CMAKE_CXX_STANDARD 23)

add_executable(Rasterization main.cpp)

add_subdirectory(src)
target_link_libraries(Rasterization PUBLIC LibRasterization)
