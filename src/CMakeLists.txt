cmake_minimum_required(VERSION 3.31)
project(LibRasterization)

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

add_library(LibRasterization
        models/Double2.cpp
        models/Double2.h
        models/Double3.cpp
        models/Double3.h
        models/Pixel.cpp
        models/Pixel.h
        Util/MathUtil.cpp
        Util/MathUtil.h
        RasterizationImplementation/ImageSlow.cpp
        RasterizationImplementation/ImageSlow.h
        Util/EnvVariables.h
        models/ModelLoader.cpp
        models/ModelLoader.h
        models/RasModel.cpp
        models/RasModel.h
        RasterizationImplementation/Rasterizer.cpp
        RasterizationImplementation/Rasterizer.h
        Util/Transformer.cpp
        Util/Transformer.h
        models/UsableModel.cpp
        models/UsableModel.h
)
if (LINUX)
    find_package(OpenMP REQUIRED)
    target_link_libraries(Rasterization PUBLIC OpenMP::OpenMP_CXX)
endif ()

target_link_libraries(LibRasterization PUBLIC raylib)
target_link_libraries(LibRasterization PUBLIC ${OpenMP_omp_LIBRARY})
