#pragma once


#include "pch.h"
#include "Core/Core.h"

#include "Core/Layer.h"

namespace Eagle
{
	typedef std::vector<Layer*> LayerVector;
	typedef std::vector<Layer*>::iterator LayerIterator;

	class EAGLE_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* layer);

		LayerIterator begin() { return stack.begin(); }
		LayerIterator end() { return stack.end(); }

	private:
		EAGLE_DISABLE_WARNING_PUSH
		LayerVector stack;
		LayerIterator currentLayer;
		EAGLE_DISABLE_WARNING_POP
	};
}