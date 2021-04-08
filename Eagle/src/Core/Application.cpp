#include "Application.h"

#include "Core/Log.h"
#include "Core/Events/ApplicationEvent.h"


Eagle::Application::~Application()
{
}

void Eagle::Application::run()
{
	WindowResizeEvent ev(800, 600);

	ENGINE_LOG(ev.toString());

	while (true)
	{
		DEBUG_LOG("We Runnin");
		//getInstance().onUpdate();
	}
}
