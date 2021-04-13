#include "LayerStack.h"

Eagle::LayerStack::LayerStack()
{
	currentLayer = stack.begin();
}

Eagle::LayerStack::~LayerStack()
{
	for (Layer* layer : stack)
		delete layer;
}

void Eagle::LayerStack::pushLayer(Layer* layer)
{
	currentLayer = stack.emplace(currentLayer, layer);
	layer->onAttach();
}

void Eagle::LayerStack::pushOverlay(Layer* layer)
{
	stack.emplace_back(layer);
	layer->onAttach();
}

