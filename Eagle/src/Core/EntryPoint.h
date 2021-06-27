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

extern auto Eagle::CreateApp() -> Application*;

auto main(int argc, char** argv) -> int
{
#ifdef EAGLE_WINDOWS
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	Eagle::Log::Init();

	ENGINE_LOG("Welcome to the Motherland");

	auto app = Eagle::CreateApp();
	app->Run();
	delete app;

	Eagle::Log::Shutdown();

	return 0;
}

//#endif