#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

EAGLE_API std::shared_ptr<spdlog::logger> Eagle::Log::engineLogger;
EAGLE_API std::shared_ptr<spdlog::logger> Eagle::Log::appLogger;

void Eagle::Log::init()
{
	spdlog::set_pattern("%^[%T][%n]: %v%$");

	engineLogger = spdlog::stdout_color_mt("EAGLE");
	appLogger = spdlog::stdout_color_mt("APP");
}

void Eagle::Log::shutdown()
{
	//delete engineLogger;
}
