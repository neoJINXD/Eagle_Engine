#include <iostream>

#ifndef GLEW_STATIC
#define GLEW_STATIC 1
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// #define MEM_LEAK
#include "shader.h"
// #include "t1.h"
#include "debug_new/debug_new.h"

//For error checking for error checking
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


int main(void)
{
    /*
    GLFWwindow* window;

    // t1* x = new t1();

    // Initialize the library
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(1024, 768, "Project Eagle", NULL, NULL);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current 
    glfwMakeContextCurrent(window);

    // Initialize GLEW
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to create GLEW" << std::endl;
		glfwTerminate();
		return -1;
	}

    // Basics shader
    Shader sh("shaders/vert.glsl","shaders/frag.glsl");

    // TODO create temp shapes
    float vertices[] = {
        -.5f, -.5f, 0.f,
         .5f, -.5f, 0.f,
        0.0f,  .5f, 0.f
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0); 
   

    // TODO have camera



    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);


    glClearColor(0.11f, 0.44f, 0.68f, 1.0f);

    float lastFrameTime = glfwGetTime();

    // Loop until the user closes the window 
    while (!glfwWindowShouldClose(window))
    {
        // deltaTime calculation
        float dt = glfwGetTime() - lastFrameTime;
        lastFrameTime += dt;

        // Clears depth and color buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // glUseProgram(shaderProgram);
        sh.use();
        // TODO Render Objects/Models
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);


        //Swap Buffers
        glfwSwapBuffers(window);

        //Check/call events
        glfwPollEvents();

        // std::cout << sango.y << std::endl;

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, true);
        }
    }

    

    glfwTerminate();
    */


    int* t = new int(0);
    
    return 0;
}