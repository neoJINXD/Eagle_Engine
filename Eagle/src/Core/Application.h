#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Utils/Singleton.h"

namespace Eagle
{
	class EAGLE_API Application
	{
	public:
		Application() = default;
		virtual ~Application();

		virtual void onUpdate() = 0;

		static void run();
	};
}
