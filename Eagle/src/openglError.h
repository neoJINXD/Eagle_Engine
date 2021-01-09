//For error checking for error checking
#include <iostream>

#ifndef GLEW_STATIC
#define GLEW_STATIC 1
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GlClearError();\
	x;\
	ASSERT(glError(#x, __FILE__, __LINE__))

static void GlClearError() {
	while (glGetError() != 0);
}

static bool glError(const char* funct, const char* file, int line) {
	while (GLenum err = glGetError()) {
		std::cout << "[OpenGL Error]: " << err << funct << " " << file << " : " << line << ";" << std::endl;
		return false;
	}
	return true;
}