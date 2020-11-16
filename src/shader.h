#pragma once

#include <string>
using std::string;

class Shader
{
public:
    Shader(string vertFilePath, string fragFilePath);
    ~Shader();

    unsigned int shaderProgram;

    void use();

private:
    string vertShader;
    string fragShader;
    unsigned int vertShaderID;
    unsigned int fragShaderID;

    string readShaderFromFile(const char* filePath);
    void compileShader();
    void linkShader();

};