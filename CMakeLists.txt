cmake_minimum_required( VERSION 3.1 )

project( Project_Eagle VERSION 0.0.0 )

# Testing Module
include(CTest)
enable_testing()

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
add_subdirectory(modules/glew EXCLUDE_FROM_ALL)
target_link_libraries(Project_Eagle PRIVATE libglew_static)

# GLM
add_subdirectory( modules/glm EXCLUDE_FROM_ALL )
target_link_libraries(Project_Eagle PRIVATE glm)

# if( MSVC )
#     SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup" )
# endif()

# target_link_libraries( Project_Eagle ${OPENGL_LIBRARIES} glfw )

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

# if( MSVC )
#     if(${CMAKE_VERSION} VERSION_LESS "3.6.0") 
#         message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'Project_Eagle' as StartUp Project in Visual Studio.\n" )
#     else()
#         set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Project_Eagle )
#     endif()
# endif()