#pragma once

#include "Core/Log.h"
#include "Core/Application.h"

//#ifdef EAGLE_WINDOWS

extern Eagle::Application* Eagle::CreateApp();

int main(int argc, char** argv)
{
	Eagle::Log::init();

	ENGINE_LOG("Welcome to the Motherland");

	auto app = Eagle::CreateApp();
	app->run();
	delete app;

	Eagle::Log::shutdown();

	return 0;
}

//#endif