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
		virtual ~Layer() {}

		virtual void onUpdate() {}
		virtual void onEvent(Event& e) {}

		inline const std::string getName() const { return name; }
	private:
		EAGLE_DISABLE_WARNING_PUSH
		std::string name;
		EAGLE_DISABLE_WARNING_POP

	};
}