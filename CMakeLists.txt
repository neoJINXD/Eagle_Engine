


cmake_minimum_required(VERSION 3.12)
project( Project_Eagle VERSION 0.0.0 )
set(CMAKE_CXX_STANDARD 17)

if (NOT WIN32)
	add_definitions(-DCMAKE_POSITION_INDEPENDENT_CODE=ON)
endif()

# # OpenGL Module
# find_package( OpenGL REQUIRED )
# include_directories( ${OPENGL_INCLUDE_DIRS} )

# Add sub-directories
# Engine Library
add_subdirectory(Eagle)
# Main Executable
add_subdirectory(Sandbox)

if (MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)
endif()
# # Grabbing Shader Files
# file(GLOB SHADER_FILES "src/shaders/*.glsl")
# file(COPY ${SHADER_FILES}
#     DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/shaders/")

# # Testing Module
# include(CTest)
# enable_testing()
# add_executable(tester tests/test_memory.cpp)
# target_link_libraries(tester PRIVATE glfw)
# target_link_libraries(tester PRIVATE libglew_static)
# target_link_libraries(tester PRIVATE glm)
# add_test(Tester tester)