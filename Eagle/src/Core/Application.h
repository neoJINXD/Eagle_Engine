#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Core/Window.h"
#include "Core/LayerStack.h"

namespace Eagle
{
	class EAGLE_API Application
	{
	public:
		Application();
		virtual ~Application();

		//static void init();
		auto Run() -> void;

		auto OnEvent(Event& e) -> void;

		auto AddLayer(Layer* layer) -> void;
		auto AddOverlay(Layer* layer) -> void;

		[[nodiscard]] inline auto GetWindow() const -> Window& { return *window; }
		[[nodiscard]] static auto GetInstance() -> Application* { return instance; }

	private:
		static Application* _instance;
		LayerStack layerStack;

		Window* window;
		bool isRunning = true;

		static Application* instance;

	private:
		auto OnClose(WindowCloseEvent& e) -> bool;
	};



	Application* CreateApp();
}
