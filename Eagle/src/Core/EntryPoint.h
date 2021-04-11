#pragma once

#include "Core/Log.h"
#include "Core/Application.h"

#ifdef EAGLE_WINDOWS

//#define _DEBUG
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
#endif

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#endif

extern Eagle::Application* Eagle::CreateApp();

int main(int argc, char** argv)
{
#ifdef EAGLE_WINDOWS
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	Eagle::Log::init();

	ENGINE_LOG("Welcome to the Motherland");

	auto app = Eagle::CreateApp(); // TODO MEMORY LEAKING
	app->run();
	delete app;

	Eagle::Log::shutdown();

	return 0;
}

//#endif