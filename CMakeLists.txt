cmake_minimum_required(VERSION 3.31)
project(Rasterization)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1  # Specify the version you need
)
FetchContent_MakeAvailable(googletest)

if (APPLE)
    message(STATUS "Using manual OpenMP flags on macOS (Apple Clang)")

    # Add compile flags individually
    add_compile_options(
            -Xpreprocessor
            -fopenmp
            -I/opt/homebrew/opt/libomp/include
    )

    # Add link flags individually
    add_link_options(
            -L/opt/homebrew/opt/libomp/lib
            -lomp
    )
endif ()

add_executable(Rasterization main.cpp)
enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
target_link_libraries(Rasterization PUBLIC LibRasterization)
