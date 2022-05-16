cmake_minimum_required(VERSION 3.18)
project(glad)
set(CMAKE_CXX_STANDARD 17)

add_library(
    glad 
    "include/glad/gl.h"
    "include/glad/vulkan.h"
    "include/KHR/khrplatform.h"
    "include/vk_platform.h"
    "src/gl.c"
    "src/vulkan.c"
)
target_include_directories(glad PUBLIC include/)