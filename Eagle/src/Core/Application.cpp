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
	window = Window::Create();
	window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
}

Eagle::Application::~Application()
{
	delete window;
}

auto Eagle::Application::Run() -> void
{
	ENGINE_LOG("Application is starting up");

	while (isRunning)
	{
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		for (Layer* layer : layerStack)
			layer->OnUpdate();
		window->Update();
	}
}

auto Eagle::Application::OnEvent(Event& e) -> void
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnClose, this, std::placeholders::_1));

	for (auto it = layerStack.end(); it != layerStack.begin();)
	{
		(*--it)->OnEvent(e);
		if (e.handled)
			break;
	}
}

auto Eagle::Application::AddLayer(Layer* layer) -> void
{
	layerStack.PushLayer(layer);
}

auto Eagle::Application::AddOverlay(Layer* layer) -> void
{
	layerStack.PushOverlay(layer);
}

auto Eagle::Application::OnClose(WindowCloseEvent& e) -> bool
{
	isRunning = false;
	return true;
}
