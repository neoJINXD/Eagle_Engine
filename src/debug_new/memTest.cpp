#include <iostream>
#include <stdio.h>
#include <memory>
#include <string>


// #ifndef GLEW_STATIC
// #define GLEW_STATIC 1
// #endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


#include "../shader.h"

#define MEM_LEAK
#include "debug_new.h"

int main()
{
    // Initialize the library
    if (!glfwInit())
        return -1;

    // Initialize GLEW
    // TODO this is breaking :c
	// if (glewInit() != GLEW_OK) {
	// 	std::cerr << "Failed to create GLEW" << std::endl;
	// 	glfwTerminate();
	// 	return -1;
	// }

    // Shader* sh = new Shader("../shaders/vert.glsl","../shaders/frag.glsl");

    printf("Unique ptr to int\n");
    // std::unique_ptr<int> t (new int(1));
    int* t = new int(0);

    
    printf("Unique ptr should be dead by now\n");
    delete (t);

    glfwTerminate();

    // delete (sh);

    return 0;
}