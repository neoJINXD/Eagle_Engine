#include "pch.h"
#include "Application.h"
#include "Core/Log.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

Eagle::Application* Eagle::Application::instance = nullptr;

Eagle::Application::Application() :
	layerStack()
{
	EAGLE_ASSERT(!instance, "Application should be a singleton!"); // TODO can i move this into a base singleton class?

	instance = this;
	window = Window::create();
	window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
}

Eagle::Application::~Application()
{
	delete window;
}

void Eagle::Application::run()
{
	ENGINE_LOG("Application is starting up");

	while (isRunning)
	{
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		for (Layer* layer : layerStack)
			layer->onUpdate();
		window->update();
	}
}

void Eagle::Application::onEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.dispatch<WindowCloseEvent>(std::bind(&Application::onClose, this, std::placeholders::_1));

	for (LayerIterator it = layerStack.end(); it != layerStack.begin();)
	{
		(*--it)->onEvent(e);
		if (e.handled)
			break;
	}
}

void Eagle::Application::addLayer(Layer* layer)
{
	layerStack.pushLayer(layer);
}

void Eagle::Application::addOverlay(Layer* layer)
{
	layerStack.pushOverlay(layer);
}

bool Eagle::Application::onClose(WindowCloseEvent& e)
{
	isRunning = false;
	return true;
}
