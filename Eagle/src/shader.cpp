#if 0
   #include "shader.h"

//#include <GL/glew.h>

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

// utility methods to pass values into the shader

void Eagle::Shader::setBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), (int)value);
}

void Eagle::Shader::setInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value);
}

void Eagle::Shader::setFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(shaderProgram, name.c_str()), value);
}

void Eagle::Shader::setVec2(const std::string& name, const glm::vec2& value) const
{
    glUniform2fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, &value[0]);
}

void Eagle::Shader::setVec2(const std::string& name, float x, float y) const
{
    glUniform2f(glGetUniformLocation(shaderProgram, name.c_str()), x, y);
}

void Eagle::Shader::setVec3(const std::string& name, const glm::vec3& value) const
{
    glUniform3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, &value[0]);
}

void Eagle::Shader::setVec3(const std::string& name, float x, float y, float z) const
{
    glUniform3f(glGetUniformLocation(shaderProgram, name.c_str()), x, y, z);
}

void Eagle::Shader::setVec4(const std::string& name, const glm::vec4& value) const
{
    glUniform4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, &value[0]);
}

void Eagle::Shader::setVec4(const std::string& name, float x, float y, float z, float w)
{
    glUniform4f(glGetUniformLocation(shaderProgram, name.c_str()), x, y, z, w);
}

void Eagle::Shader::setMat2(const std::string& name, const glm::mat2& mat) const
{
    glUniformMatrix2fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Eagle::Shader::setMat3(const std::string& name, const glm::mat3& mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Eagle::Shader::setMat4(const std::string& name, const glm::mat4& mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
#endif