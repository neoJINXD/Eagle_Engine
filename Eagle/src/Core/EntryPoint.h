#pragma once

#include "Core/Log.h"
#include "Core/Application.h"

#ifdef EAGLE_WINDOWS

int main(int argc, char** argv)
{
	Eagle::Log::init();

	ENGINE_LOG("Welcome to the Motherland");

	Eagle::Application::run();

	return 0;
}

#endif