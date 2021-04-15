if (WIN32)
    add_compile_definitions(EAGLE_WINDOWS)
endif()

file(GLOB_RECURSE Sandbox_CPP "src/*.cpp")
file(GLOB_RECURSE Sandbox_H "src/*.h")

# Sandbox EXE
add_executable(
    Sandbox 
    ${Sandbox_CPP}
    ${Sandbox_H}
    )


# target_include_directories(EAGLE_SANDBOX PRIVATE ${EAGLE_SANDBOX_DIR})
# target_include_directories(EAGLE_SANDBOX PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)

target_link_libraries(Sandbox PRIVATE Eagle)

# Grabbing Shader Files
add_custom_command(TARGET Sandbox PRE_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory 
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/shaders/ $<TARGET_FILE_DIR:Sandbox>/shaders/)

add_custom_command(TARGET Sandbox PRE_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory 
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/shaders/ $<TARGET_FILE_DIR:Sandbox>/../shaders/)



if(WIN32)
	file(GLOB_RECURSE SANDBOX_SRC RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*.cpp" "*.h")
	source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SANDBOX_SRC})
endif()