file(GLOB Sandbox_CPP "src/*.cpp")
file(GLOB Sandbox_H "src/*.h")

# Sandbox EXE
add_executable(
    Sandbox 
    ${Sandbox_CPP}
    ${Sandbox_H}
    )


# target_include_directories(EAGLE_SANDBOX PRIVATE ${EAGLE_SANDBOX_DIR})
# target_include_directories(EAGLE_SANDBOX PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)

target_link_libraries(Sandbox PRIVATE Eagle)
