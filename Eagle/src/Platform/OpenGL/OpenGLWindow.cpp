
#include "pch.h"
#include "OpenGLWindow.h"

#include "Core/Events/ApplicationEvent.h"
#include "Core/Events/KeyboardEvent.h"
#include "Core/Events/MouseEvent.h"

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

	glfwSetWindowFocusCallback(window, [](GLFWwindow* window, int focusStatus) {
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		switch (focusStatus)
		{
		case GLFW_TRUE:
		{
			WindowFocusEvent e;
			data.callback(e);
			break;
		}
		case GLFW_FALSE:
		{
			WindowUnfocusEvent e;
			data.callback(e);
			break;
		}
		}
	});

	glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		WindowResizeEvent e(width, height);
		data.callback(e);
	});

	glfwSetKeyCallback(window, [](GLFWwindow* window, int keycode, int scancode, int action, int mods) {
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		switch (action)
		{
		case GLFW_PRESS:
		{
			KeyDownEvent e(keycode);
			data.callback(e);
			break;
		}
		case GLFW_RELEASE:
		{
			KeyUpEvent e(keycode);
			data.callback(e);
			break;
		}
		case GLFW_REPEAT:
		{
			// TODO still need to setup key holding
			KeyDownEvent e(keycode);
			data.callback(e);
			break;
		}
		}
	});
	
	glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int buttonID, int action, int mods) {
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		
		switch (action)
		{
		case GLFW_PRESS:
		{
			MouseButtonDownEvent e(buttonID);
			data.callback(e);
			break;
		}
		case GLFW_RELEASE:
		{
			MouseButtonUpEvent e(buttonID);
			data.callback(e);
			break;
		}
		}
	});

	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPos, double yPos) {
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		
		MouseMovedEvent e((float)xPos, (float)yPos);
		data.callback(e);
	});

	glfwSetScrollCallback(window, [](GLFWwindow* window, double xDelta, double yDelta) {
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		MouseScrollEvent e((float)xDelta, (float)yDelta);
		data.callback(e);
	});
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



