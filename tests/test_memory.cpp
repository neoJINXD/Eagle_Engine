
#include <stdio.h>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>



int main()
{
    // Initialize the library
    printf("Initializing glfw");
    if (!glfwInit())
        return -1;

    printf("Creating window");
    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(1024, 768, "Project Eagle", NULL, NULL);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    printf("Making window current context");
    // Make the window's context current 
    glfwMakeContextCurrent(window);

    printf("Initializing glew");
    // WARNING Make sure to initialize GLFW window and set as main context otherwise this fails
    // Initialize GLEW
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to create GLEW" << std::endl;
		glfwTerminate();
		return -1;
	}

    // Shader* sh = new Shader("../shaders/vert.glsl","../shaders/frag.glsl");

    printf("ptr to int\n");
    int* t = new int(0);

    
    printf("ptr should be dead by now\n");
    delete (t);

    glfwTerminate();

    // delete (sh);

    return 0;
}