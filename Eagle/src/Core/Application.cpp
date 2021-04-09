#include "Application.h"

#include "Core/Log.h"
#include "Core/Events/ApplicationEvent.h"

//Eagle::Application* Eagle::Application::_instance;

Eagle::Application::Application()
{
	
}

Eagle::Application::~Application()
{
}



void Eagle::Application::run()
{
	WindowResizeEvent ev(800, 600);

	ENGINE_LOG(ev.toString());

	//int x = 0;

	while (true)
	{
		//x++;
		//DEBUG_LOG("We Runnin {}", x);
		onUpdate();
		//getInstance().onUpdate();
		//getInstance().onUpdate();
	}
}
