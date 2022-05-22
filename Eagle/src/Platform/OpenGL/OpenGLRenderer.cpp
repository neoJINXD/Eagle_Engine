#include "pch.h"
#include "OpenGLRenderer.h"

#include "glad/gl.h"

Eagle::Renderer* Eagle::Renderer::create()
{
   return new OpenGLRenderer();
}

Eagle::OpenGLRenderer::OpenGLRenderer()
{
   ENGINE_LOG("OpenGL Renderer initialized");

   // TEMP

   //unsigned int VBO;
   glGenVertexArrays(1, &VAO);
   glGenBuffers(1, &VBO);
   glBindVertexArray(VAO);

   glBindBuffer(GL_ARRAY_BUFFER, VBO);
   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
   glEnableVertexAttribArray(0);

   glBindBuffer(GL_ARRAY_BUFFER, 0);
   glBindVertexArray(0);


   const char* vertexShaderSource = "#version 430 core\n"
                                    "layout (location = 0) in vec3 aPos;\n"
                                    "void main()\n"
                                    "{\n"
                                    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                    "}\0";
   const char* fragmentShaderSource = "#version 430 core\n"
                                      "out vec4 FragColor;\n"
                                      "void main()\n"
                                      "{\n"
                                      "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                      "}\0";

   unsigned int vertShader;
   vertShader = glCreateShader(GL_VERTEX_SHADER);
   glShaderSource(vertShader, 1, &vertexShaderSource, nullptr);
   glCompileShader(vertShader);

   unsigned int fragShader;
   fragShader = glCreateShader(GL_FRAGMENT_SHADER);
   glShaderSource(fragShader, 1, &fragmentShaderSource, nullptr);
   glCompileShader(fragShader);

   //unsigned int shaderProgram;
   shaderProgram = glCreateProgram();
   glAttachShader(shaderProgram, vertShader);
   glAttachShader(shaderProgram, fragShader);
   glLinkProgram(shaderProgram);

   glDeleteShader(vertShader);
   glDeleteShader(fragShader);
}

Eagle::OpenGLRenderer::~OpenGLRenderer() {}

void Eagle::OpenGLRenderer::startFrame() const
{
   glClearColor(1, 1, 1, 1); // TODO not hardcoded
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glViewport(0, 0, 1280, 720); // TODO not hardcoded
}

void Eagle::OpenGLRenderer::endFrame() const
{
   checkGlErrors();
}

void Eagle::OpenGLRenderer::render() const 
{
   glUseProgram(shaderProgram);
   glBindVertexArray(VAO);
   glDrawArrays(GL_TRIANGLES, 0, 3);
   glBindVertexArray(0);
}

void Eagle::OpenGLRenderer::checkGlErrors() const
{
   static bool checkingForErrors = true;
   while (checkingForErrors != false)
   {
      const char* errorString = nullptr;

      // WARNING: feels like bad code
      switch (glGetError())
      {
         case GL_NO_ERROR:
            return;
         case GL_INVALID_ENUM:
            errorString = "GL_INVALID_ENUM";
            break;
         case GL_INVALID_VALUE:
            errorString = "GL_INVALID_VALUE";
            break;
         case GL_INVALID_OPERATION:
            errorString = "GL_INVALID_OPERATION";
            break;
         case GL_INVALID_FRAMEBUFFER_OPERATION:
            errorString = "GL_INVALID_FRAMEBUFFER_OPERATION";
            break;
         case GL_OUT_OF_MEMORY:
            errorString = "GL_OUT_OF_MEMORY";
            break;
         default:
            errorString = "UNKNOWN";
            break;
      }

      ENGINE_ERR("OPENGL ERROR DETECTED: {}", errorString);
   }
}
