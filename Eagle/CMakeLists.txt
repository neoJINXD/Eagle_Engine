add_compile_definitions(EAGLE_WINDOWS)
add_compile_definitions(EAGLE_LIB)

file(GLOB_RECURSE Eagle_CPP "src/*.cpp")
file(GLOB_RECURSE Eagle_H "src/*.h")

# Eagle Library
add_library(
    Eagle SHARED
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


# Vulkan
find_package(Vulkan REQUIRED)
target_link_libraries(Eagle PRIVATE Vulkan::Vulkan)

# target_include_directories(EAGLE_LIB PUBLIC ${EAGLE_SRC_DIR})
target_include_directories(Eagle PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

