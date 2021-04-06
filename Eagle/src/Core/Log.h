#pragma once

#include "Core/Core.h"
#include <memory>
#include <string>

#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#pragma warning(pop)

namespace Eagle
{
	class EAGLE_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getEngineLog() { return engineLogger; }
		inline static std::shared_ptr<spdlog::logger>& getApplicationLog() { return appLogger; }

	private:
		static std::shared_ptr<spdlog::logger> engineLogger;
		static std::shared_ptr<spdlog::logger> appLogger;
	};
}

#ifdef EAGLE_LIB
	#define ENGINE_LOG(...)  Eagle::Log::getEngineLog()->info(__VA_ARGS__)
	#define ENGINE_WARN(...) Eagle::Log::getEngineLog()->warn(__VA_ARGS__)
	#define ENGINE_ERR(...)  Eagle::Log::getEngineLog()->error(__VA_ARGS__)
#endif

#define DEBUG_ERR(...)  Eagle::Log::getApplicationLog()->error(__VA_ARGS__)
#define DEBUG_LOG(...)  Eagle::Log::getApplicationLog()->info(__VA_ARGS__)
#define DEBUG_WARN(...) Eagle::Log::getApplicationLog()->warn(__VA_ARGS__)