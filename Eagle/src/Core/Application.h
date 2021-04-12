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
		void run();

		void onEvent(Event& e);

		void addLayer(Layer* layer);
		void addOverlay(Layer* layer);

	private:
		static Application* _instance;
		LayerStack layerStack;

		Window* window;
		bool isRunning = true;

	private:
		bool onClose(WindowCloseEvent& e);
	};

	Application* CreateApp();
}
