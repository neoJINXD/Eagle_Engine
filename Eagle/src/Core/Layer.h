#pragma once

#include "pch.h"
#include "Core/Core.h"
#include "Core/Events/Event.h"

namespace Eagle
{
	class EAGLE_API Layer
	{
	public:
		Layer(const std::string& _name = "LayerName") : name(_name) {}
		virtual ~Layer() = default;

		virtual auto OnAttach() -> void {}
		virtual auto OnDetach() -> void {}
		virtual auto OnUpdate() -> void {}
		virtual auto OnEvent(Event& e) -> void {}

		[[nodiscard]] inline auto GetName() const -> std::string { return name; }
	private:
		EAGLE_DISABLE_WARNING_PUSH
		std::string name;
		EAGLE_DISABLE_WARNING_POP

	};
}