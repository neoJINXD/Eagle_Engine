#include "Application.h"

#include "Core/Log.h"
#include "Core/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

//Eagle::Application* Eagle::Application::_instance;

Eagle::Application::Application()
{
	window = Window::create();
}

Eagle::Application::~Application()
{
	delete window;
	glfwTerminate();
}



void Eagle::Application::run()
{
	//WindowResizeEvent ev(800, 600);

	ENGINE_LOG("Application is starting up");

	//while (isRunning)
	//{
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		//onUpdate(); // TODO MEMORY LEAKING
		window->update();
	//}
}
