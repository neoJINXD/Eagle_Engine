#pragma once
#include "Core/Renderer/Renderer.h"

namespace Eagle
{
   class OpenGLRenderer : public Renderer
   {
    public:
      OpenGLRenderer();
      ~OpenGLRenderer() override;

      void startFrame() const override;
      void endFrame() const override;
      void render() const override;

    private:
      void checkGlErrors() const;

      float vertices[9] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

      unsigned int shaderProgram;
      unsigned int VBO, VAO;
   };
}
