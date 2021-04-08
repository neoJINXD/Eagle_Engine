#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Utils/Singleton.h"

namespace Eagle
{
	class EAGLE_API Application
	{
	public:
		//Application() = default;
		Application();
		virtual ~Application();

		virtual void onUpdate() = 0;

		//static void init();
		void run();


	private:
		static Application* _instance;
	};

	Application* CreateApp();
}
