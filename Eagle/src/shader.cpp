#include "shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

#ifndef GLEW_STATIC
#define GLEW_STATIC 1
#endif

#include <GL/glew.h>

Eagle::Shader::Shader(string vertFilePath, string fragFilePath)
{
    vertShader = readShaderFromFile(vertFilePath.c_str());
    fragShader = readShaderFromFile(fragFilePath.c_str());

    compileShader();
    linkShader();
}

Eagle::Shader::~Shader()
{
    //TODO
}


string Eagle::Shader::readShaderFromFile(const char* fileName)
{
    string content;
    std::ifstream input(fileName, std::ios::in);

    // Stops program if file stream fails to initialize
    if (!input.good())
    {
        std::cerr << "ERROR::SHADER::INVALID_FILE_INPUT" << std::endl;
        exit(-1); // TODO have some return that can be tested in the tests
    }

    // Reads file
    if (input.good())
    {
        std::stringstream ss;
        ss << input.rdbuf();
        content = ss.str();
        input.close();
    }

    return content;
}

void Eagle::Shader::compileShader()
{
    int success;
    char infoLog[512];

    // Vertex Shader
    vertShaderID = glCreateShader(GL_VERTEX_SHADER);
    const char* vertSource = vertShader.c_str();
    glShaderSource(vertShaderID, 1, &vertSource, NULL);
    glCompileShader(vertShaderID);

    // verification
    glGetShaderiv(vertShaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertShaderID, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl; 
    }


    // Fragment Shader
    fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragSource = fragShader.c_str();
    glShaderSource(fragShaderID, 1, &fragSource, NULL);
    glCompileShader(fragShaderID);

    // verification
    glGetShaderiv(fragShaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragShaderID, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl; 
    }
}

void Eagle::Shader::linkShader()
{
    // Linking Shader
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertShaderID);
    glAttachShader(shaderProgram, fragShaderID);
    glLinkProgram(shaderProgram);

    // verification
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDetachShader(shaderProgram, vertShaderID);
    glDetachShader(shaderProgram, fragShaderID);

    // TODO might wanna move this to destructor, not sure
    glDeleteShader(vertShaderID);
    glDeleteShader(fragShaderID);
}

void Eagle::Shader::use()
{
    glUseProgram(shaderProgram);
}

// TODO add utility methods to pass values into the shader