#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Core/Window.h"
#include "Core/LayerStack.h"
#include "Core/ImGui/ImGuiLayer.h"

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

		inline Window& getWindow() { return *window; }
		static Application* getInstance() { return instance; }

	protected:
		ImGuiContext* ImgGuiCtx;

	private:
		static Application* _instance;
		LayerStack layerStack;

		ImGuiLayer* _ImGuiLayer;

		Window* window;
		bool isRunning = true;

		static Application* instance;

	private:
		bool onClose(WindowCloseEvent& e);
	};



	Application* CreateApp();
}
