# Project Eagle

![Linux Build](https://github.com/neojinxd/Eagle_Engine/workflows/Eagle_Ubuntu/badge.svg)
![Windows Build](https://github.com/neojinxd/Eagle_Engine/workflows/Eagle_Windows/badge.svg)

## Building a game engine from scratch using OpenGL and Vulkan and C++

---

### Getting Started

To clone with the submodules run ```git clone --recursive```

This project is setup using [CMake](https://cmake.org/download/).
Currently supports Visual Studio and the VSCode extension [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools).

The project is split into seperate targets:

- Eagle : Core library for the engine specific code
- Sandbox : Base project, acts as a game using the engine code
- tester : Tests made for the Core lib (STILL NEEDS TO BE SETUP)

---

### Libraries used

These libraries are setup as submodules within this repo

- GLEW (OpenGL Extension Wrangler)
- GLFW
- GLM (OpenGL Mathematics)
