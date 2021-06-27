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
		static auto Init() -> void;
		static auto Shutdown() -> void;

		inline static auto GetEngineLog() -> std::shared_ptr<spdlog::logger>& { return engineLogger; }
		inline static auto GetApplicationLog() -> std::shared_ptr<spdlog::logger>& { return appLogger; }

	private:
EAGLE_DISABLE_WARNING_PUSH
		static std::shared_ptr<spdlog::logger> engineLogger;
		static std::shared_ptr<spdlog::logger> appLogger;
EAGLE_DISABLE_WARNING_POP
	};
}


#define ENGINE_TRACE(...)     Eagle::Log::GetEngineLog()->trace(__VA_ARGS__)
#define ENGINE_LOG(...)       Eagle::Log::GetEngineLog()->info(__VA_ARGS__)
#define ENGINE_WARN(...)      Eagle::Log::GetEngineLog()->warn(__VA_ARGS__)
#define ENGINE_ERR(...)	      Eagle::Log::GetEngineLog()->error(__VA_ARGS__)
#define ENGINE_CRITICAL(...)  Eagle::Log::GetEngineLog()->critical(__VA_ARGS__)


#define DEBUG_LOG(...)  Eagle::Log::GetApplicationLog()->trace(__VA_ARGS__)
#define DEBUG_WARN(...) Eagle::Log::GetApplicationLog()->warn(__VA_ARGS__)
#define DEBUG_ERR(...)  Eagle::Log::GetApplicationLog()->error(__VA_ARGS__)

#define PRINT(...) DEBUG_LOG(__VA_ARGS__)