#include "shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

#ifndef GLEW_STATIC
#define GLEW_STATIC 1
#endif

#include <GL/glew.h>

Shader::Shader(string vertFilePath, string fragFilePath)
{
    //TODO
}

Shader::~Shader()
{
    //TODO
}


string Shader::readShaderFromFile(const char* fileName)
{
    string content;
    std::ifstream input(fileName, std::ios::in);

    // Stops program if file stream fails to initialize
    if (!input.good())
    {
        std::cerr << "SHADER::INVALID_FILE_INPUT" << std::endl;
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

void Shader::compileShader()
{
    //TODO
}

void Shader::linkShader()
{
    //TODO
}

void Shader::use()
{
    //TODO
}

// TODO add utility methods to pass values into the shader