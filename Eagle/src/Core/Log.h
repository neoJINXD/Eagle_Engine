#pragma once

#include "pch.h"

#include "Core/Core.h"

#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#pragma warning(pop)

namespace Eagle
{
	class EAGLE_API Log
	{
	public:
		static void init();
		static void shutdown();

		inline static std::shared_ptr<spdlog::logger>& getEngineLog() { return engineLogger; }
		inline static std::shared_ptr<spdlog::logger>& getApplicationLog() { return appLogger; }

	private:
EAGLE_DISABLE_WARNING_PUSH
		static std::shared_ptr<spdlog::logger> engineLogger;
		static std::shared_ptr<spdlog::logger> appLogger;
EAGLE_DISABLE_WARNING_POP
	};
}


#define ENGINE_TRACE(...)     Eagle::Log::getEngineLog()->trace(__VA_ARGS__)
#define ENGINE_LOG(...)       Eagle::Log::getEngineLog()->info(__VA_ARGS__)
#define ENGINE_WARN(...)      Eagle::Log::getEngineLog()->warn(__VA_ARGS__)
#define ENGINE_ERR(...)	      Eagle::Log::getEngineLog()->error(__VA_ARGS__)
#define ENGINE_CRITICAL(...)  Eagle::Log::getEngineLog()->critical(__VA_ARGS__)


#define DEBUG_LOG(...)  Eagle::Log::getApplicationLog()->info(__VA_ARGS__)
#define DEBUG_WARN(...) Eagle::Log::getApplicationLog()->warn(__VA_ARGS__)
#define DEBUG_ERR(...)  Eagle::Log::getApplicationLog()->error(__VA_ARGS__)

#define PRINT(...) DEBUG_LOG(__VA_ARGS__)