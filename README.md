# Project Eagle

![Linux Build](https://github.com/neojinxd/Eagle_Engine/workflows/Eagle_Ubuntu/badge.svg)
<!-- ![Windows Build](https://github.com/neojinxd/Eagle_Engine/workflows/Eagle_Windows/badge.svg) -->

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

### How to Run


```bash
mkdir build
cd build
cmake ..
```

After this, based on your compiler you can either just run `make` on Linux with the MinGW compiler or open the generated solution file if using MSVC

---

### Libraries used

These libraries are setup as submodules within this repo

- GLEW (OpenGL Extension Wrangler)
- GLFW
- GLM (OpenGL Mathematics)
- spdlog
