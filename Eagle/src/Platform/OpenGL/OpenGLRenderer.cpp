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

   unsigned int VBO;
   glGenBuffers(1, &VBO);
   glBindBuffer(GL_ARRAY_BUFFER, VBO);
   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


}

Eagle::OpenGLRenderer::~OpenGLRenderer() {}

void Eagle::OpenGLRenderer::startFrame() const
{
   glClearColor(0, 1, 1, 1); // TODO not hardcoded
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glViewport(0, 0, 1280, 720); // TODO not hardcoded
}

void Eagle::OpenGLRenderer::endFrame() const
{
   checkGlErrors();
}

void Eagle::OpenGLRenderer::render() const 
{
    
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
