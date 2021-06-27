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

auto Eagle::LayerStack::PushLayer(Layer* layer) -> void
{
	currentLayer = stack.emplace(currentLayer, layer);
	layer->OnAttach();
}

auto Eagle::LayerStack::PushOverlay(Layer* layer) -> void
{
	stack.emplace_back(layer);
	layer->OnAttach();
}

