#include "LayerStack.h"

Eagle::LayerStack::LayerStack()
{
}

Eagle::LayerStack::~LayerStack()
{
	for (Layer* layer : stack)
		delete layer;
}

void Eagle::LayerStack::pushLayer(Layer* layer)
{
	stack.emplace(stack.begin() + currentLayerIndex, layer);
	currentLayerIndex++;
	layer->onAttach();
}

void Eagle::LayerStack::pushOverlay(Layer* layer)
{
	stack.emplace_back(layer);
	layer->onAttach();
}

