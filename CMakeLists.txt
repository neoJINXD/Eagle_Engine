cmake_minimum_required( VERSION 3.1 )

project( Project_Eagle VERSION 0.0.0 )


# OpenGL Module
find_package( OpenGL REQUIRED )
include_directories( ${OPENGL_INCLUDE_DIRS} )

# Main Executable
# set( Project_Eagle-SRC
#      src/main.cpp
#      )

file(GLOB Project_Eagle-SRC
"src/*.h"
"src/*.cpp"
)

add_executable( Project_Eagle ${Project_Eagle-SRC} )

# GLFW
add_subdirectory( modules/glfw )
target_link_libraries(Project_Eagle PRIVATE glfw)
# set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
# set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

# GLEW
add_definitions(-DGLEW_STATIC)
add_subdirectory(modules/glew-cmake EXCLUDE_FROM_ALL)
target_link_libraries(Project_Eagle PRIVATE libglew_static)

# GLM
add_subdirectory( modules/glm EXCLUDE_FROM_ALL )
target_link_libraries(Project_Eagle PRIVATE glm)

# Grabbing Shader Files
file(GLOB SHADER_FILES "src/shaders/*.glsl")
file(COPY ${SHADER_FILES}
    DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/shaders/")

# Testing Module
include(CTest)
# enable_testing()
add_executable(tester tests/temp.cpp)
add_test(Tester tester)