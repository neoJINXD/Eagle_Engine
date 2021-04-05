#pragma once

#include "Core.h"

//#define EAGLE_API __declspec(dllexport)

namespace Eagle
{
	class EAGLE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	//Application* CreateApplication();
}
