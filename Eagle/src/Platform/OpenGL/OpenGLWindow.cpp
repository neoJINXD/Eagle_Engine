
#include "pch.h"
#include "OpenGLWindow.h"
#include "Core/Log.h"

static bool GLFWInitialized = false;

Eagle::Window* Eagle::Window::create()
{
	return new OpenGLWindow();
}

Eagle::OpenGLWindow::OpenGLWindow(const std::string& _title, unsigned int _width, unsigned int _height)
{
	data.title = _title; 
	data.width = _width; 
	data.height = _height;

	ENGINE_LOG("OpenGL Window Create with Title: {}, Width: {}, Height: {}", data.title, data.width, data.height);

	if (!GLFWInitialized)
	{
		int succ = glfwInit();
		
		if (!succ)
		{
			ENGINE_ERR("FAILED TO INIT GLFW!");
			__debugbreak(); // TODO move this out to only run on windows
		}

		GLFWInitialized = true;
	}

	window = glfwCreateWindow(data.width, data.height, data.title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(window);
	
	setVSync(true);
}

Eagle::OpenGLWindow::~OpenGLWindow()
{
	glfwDestroyWindow(window);
}

void Eagle::OpenGLWindow::update()
{
	glfwPollEvents();
	glfwSwapBuffers(window);
}

void Eagle::OpenGLWindow::setVSync(bool enabled)
{
	if (enabled)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);

	data.vSync = enabled;
}

bool Eagle::OpenGLWindow::getVSync() const
{
	return data.vSync;
}



