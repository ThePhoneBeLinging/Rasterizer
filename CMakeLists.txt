cmake_minimum_required(VERSION 3.31)
project(Rasterization)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

# GLFW
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.3.10
)
FetchContent_MakeAvailable(glfw)
set_target_properties(glfw PROPERTIES
        FOLDER "glfw"
)
# Optionally disable tests/docs/examples
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)

# GLAD
FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
        GIT_TAG v2.0.6
)
FetchContent_MakeAvailable(glad)

set(CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH}
        ${glad_SOURCE_DIR}/cmake)
include(${glad_SOURCE_DIR}/cmake/GladConfig.cmake)
add_subdirectory(${glad_SOURCE_DIR}/cmake glad_cmake)

set(GLAD_LIBRARY glad_gl_core_46)
glad_add_library(${GLAD_LIBRARY} SHARED API gl:core=4.6)
set_target_properties(${GLAD_LIBRARY} PROPERTIES
        FOLDER "glad"
)

install(TARGETS ${GLAD_LIBRARY}
        EXPORT ${GLAD_LIBRARY}-targets
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)


# GLM
FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.1
)
FetchContent_MakeAvailable(glm)
set_target_properties(glm PROPERTIES
        FOLDER "glm"
)

add_executable(Rasterization main.cpp
        src/models/Double2.cpp
        src/models/Double2.h
        src/models/Double3.cpp
        src/models/Double3.h
        src/models/Pixel.cpp
        src/models/Pixel.h
        src/Util/MathUtil.cpp
        src/Util/MathUtil.h
        src/Util/EnvVariables.h
        src/models/ModelLoader.cpp
        src/models/ModelLoader.h
        src/models/Model.cpp
        src/models/Model.h
        src/Util/Transformer.cpp
        src/Util/Transformer.h
        src/Util/OpenGLUtil.cpp
        src/Util/OpenGLUtil.h
)

target_link_libraries(Rasterization PUBLIC
        glm
        glfw
        ${GLAD_LIBRARY}
)
