#include "pch.h"
#include "Application.h"
#include "Core/Log.h"

#include <GLFW/glfw3.h>


Eagle::Application::Application()
{
	window = Window::create();
	window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
}

Eagle::Application::~Application()
{
	delete window;
}

void Eagle::Application::run()
{
	//WindowResizeEvent ev(800, 600);

	ENGINE_LOG("Application is starting up");

	while (isRunning)
	{
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		//onUpdate(); // TODO MEMORY LEAKING
		window->update();
	}
}

void Eagle::Application::onEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.dispatch<WindowCloseEvent>(std::bind(&Application::onClose, this, std::placeholders::_1));
	ENGINE_LOG("{}", e);
}

bool Eagle::Application::onClose(WindowCloseEvent& e)
{
	isRunning = false;
	return true;
}
