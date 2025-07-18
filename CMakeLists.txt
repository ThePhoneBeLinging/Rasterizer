cmake_minimum_required(VERSION 3.31)
project(Rasterization)

set(CMAKE_CXX_STANDARD 23)

set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        FetchContent_MakeAvailable(raylib)
    endif ()
endif ()


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

add_executable(Rasterization main.cpp
        src/models/Double2.cpp
        src/models/Double2.h
        src/models/Double3.cpp
        src/models/Double3.h
        src/models/Pixel.cpp
        src/models/Pixel.h
        src/MathUtil.cpp
        src/MathUtil.h
        src/models/ImageSlow.cpp
        src/models/ImageSlow.h
        src/EnvVariables.h
        src/models/ModelLoader.cpp
        src/models/ModelLoader.h
        src/models/RasModel.cpp
        src/models/RasModel.h
        src/Rasterizers/Rasterizer.cpp
        src/Rasterizers/Rasterizer.h
        src/Transformer.cpp
        src/Transformer.h
)

target_link_libraries(Rasterization PUBLIC raylib)
target_link_libraries(Rasterization PUBLIC ${OpenMP_omp_LIBRARY})
