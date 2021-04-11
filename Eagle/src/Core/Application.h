#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Core/Window.h"

namespace Eagle
{
	class EAGLE_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void onUpdate() = 0;

		//static void init();
		void run();

		void onEvent(Event& e);


	private:
		static Application* _instance;

		Window* window;
		bool isRunning = true;

	private:
		bool onClose(WindowCloseEvent& e);
	};

	Application* CreateApp();
}
