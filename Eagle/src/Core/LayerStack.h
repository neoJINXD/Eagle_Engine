#pragma once


#include "pch.h"
#include "Core/Core.h"

#include "Core/Layer.h"

namespace Eagle
{
	typedef std::vector<Layer*> LayerVector;
	typedef std::vector<Layer*>::iterator LayerIterator;

	class EAGLE_API LayerStack final
	{
	public:
		LayerStack();
		~LayerStack();

		auto PushLayer(Layer* layer) -> void;
		auto PushOverlay(Layer* layer) -> void;

		auto begin() -> LayerIterator { return stack.begin(); }
		auto end() -> LayerIterator { return stack.end(); }

	private:
		EAGLE_DISABLE_WARNING_PUSH
		LayerVector stack;
		LayerIterator currentLayer;
		EAGLE_DISABLE_WARNING_POP
	};
}