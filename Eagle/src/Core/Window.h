#pragma once

#include "pch.h"

#include "Core/Core.h"
#include "Core/Events/Event.h"


namespace Eagle
{
	class EAGLE_API Window
	{
	public:
		using EventCallback = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual auto Update() -> void = 0;

		[[nodiscard]] virtual auto GetWidth() const -> unsigned int = 0;
		[[nodiscard]] virtual auto GetHeight() const -> unsigned int = 0;

		virtual auto SetEventCallback(const EventCallback& callback) -> void = 0;

		virtual auto SetVSync(bool enabled) -> void = 0;
		[[nodiscard]] virtual auto GetVSync() const -> bool = 0;

		[[nodiscard]] virtual auto GetWindow() const -> void* = 0;

		static auto Create() -> Window*;

	};
}