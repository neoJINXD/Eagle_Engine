# set (EAGLE_SANDBOX_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# file(GLOB EAGLE_SANDBOX_SRC
#     "src/*.h"
#     "src/*.cpp"
# )

# add_executable(EAGLE_SANDBOX ${EAGLE_SANDBOX_SRC})
add_executable(Sandbox src/main.cpp)


# target_include_directories(EAGLE_SANDBOX PRIVATE ${EAGLE_SANDBOX_DIR})
# target_include_directories(EAGLE_SANDBOX PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)

target_link_libraries(Sandbox PRIVATE Eagle)
