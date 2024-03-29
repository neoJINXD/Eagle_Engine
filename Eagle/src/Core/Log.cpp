#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

std::shared_ptr<spdlog::logger> Eagle::Log::engineLogger;
std::shared_ptr<spdlog::logger> Eagle::Log::appLogger;

void Eagle::Log::init()
{
	spdlog::set_pattern("%^[%T][%n]: %v%$");

	engineLogger = spdlog::stdout_color_mt("EAGLE");
	appLogger = spdlog::stdout_color_mt("APP");
	engineLogger->set_level(spdlog::level::trace);
	appLogger->set_level(spdlog::level::trace);
}

void Eagle::Log::shutdown()
{
	//delete engineLogger;
}
