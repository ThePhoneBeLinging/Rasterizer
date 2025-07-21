cmake_minimum_required(VERSION 3.25)
project(Rasterization_Tests)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SRC_FILES ../src/*.cpp ../src/models/*.cpp ../src/RasterizationImplementation/*.cpp)

set(SOURCES
        TimingTests.cpp
        ${SRC_FILES}
)
add_executable(Rasterization_Tests ${SOURCES})

target_link_libraries(Rasterization_Tests PUBLIC
        GTest::gtest
        GTest::gtest_main
        LibRasterization
)