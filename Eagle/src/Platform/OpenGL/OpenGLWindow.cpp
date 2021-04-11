
#include "pch.h"
#include "OpenGLWindow.h"

#include "Core/Events/ApplicationEvent.h"

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
		EAGLE_ASSERT(succ, "FAILED TO INIT GLFW!");
		GLFWInitialized = true;
	}

	window = glfwCreateWindow(data.width, data.height, data.title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwSetWindowUserPointer(window, &data);
	
	setVSync(true);

	glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		WindowCloseEvent e;
		data.callback(e);
	});

	/*glfwSetKeyCallback(window, [](GLFWwindow* win, int keycode, int scancode, int action, int mods) {

	});*/
}

Eagle::OpenGLWindow::~OpenGLWindow()
{
	glfwDestroyWindow(window);
	glfwTerminate();
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



