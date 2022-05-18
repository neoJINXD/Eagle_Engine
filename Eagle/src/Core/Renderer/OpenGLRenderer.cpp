#include "pch.h"
#include "OpenGLRenderer.h"

#include "glad/gl.h"

Eagle::Renderer* Eagle::Renderer::create()
{
	return new OpenGLRenderer();
}

Eagle::OpenGLRenderer::OpenGLRenderer()
{
	//EAGLE_ASSERT(!instance, "Application should be a singleton!"); // TODO can i move this into a base singleton class?
	ENGINE_LOG("OpenGL Renderer initialized");
	//instance = this;
}

Eagle::OpenGLRenderer::~OpenGLRenderer()
{
}

void Eagle::OpenGLRenderer::startFrame() const
{
	glClearColor(0, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Eagle::OpenGLRenderer::endFrame() const
{
	checkGlErrors();
}

void Eagle::OpenGLRenderer::checkGlErrors() const
{
	static bool checkingForErrors = true;
	while (checkingForErrors != false)
	{
		const char* errorString = NULL;
		//bool retVal = false;

		// WARNING: feels like bad code
		switch (glGetError())
		{
		case GL_NO_ERROR:
			//retVal = true;
			return;
			break;
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
