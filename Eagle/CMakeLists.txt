# set (EAGLE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# file(GLOB EAGLE_LIB_SRC
#     "src/*.h"
#     "src/*.cpp"
# )
file(GLOB Eagle_CPP "src/*.cpp")
file(GLOB Eagle_H "src/*.h")

# add_library(EAGLE_LIB SHARED ${Eagle_LIB_SRC})
add_library(
    Eagle STATIC
    ${Eagle_CPP}
    ${Eagle_H}
    )

# GLFW
add_subdirectory( ${PROJECT_SOURCE_DIR}/modules/glfw modules/glfw )
target_link_libraries(Eagle PRIVATE glfw)
# set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
# set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

# GLEW
add_definitions(-DGLEW_STATIC)
add_subdirectory( ${PROJECT_SOURCE_DIR}/modules/glew-cmake modules/glew-cmake EXCLUDE_FROM_ALL)
target_link_libraries(Eagle PRIVATE libglew_static)

# GLM
add_subdirectory( ${PROJECT_SOURCE_DIR}/modules/glm modules/glm EXCLUDE_FROM_ALL )
target_link_libraries(Eagle PRIVATE glm)

# target_include_directories(EAGLE_LIB PUBLIC ${EAGLE_SRC_DIR})
target_include_directories(Eagle PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
