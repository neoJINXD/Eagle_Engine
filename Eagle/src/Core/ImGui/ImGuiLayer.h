#pragma once

#include "Core/Layer.h"

namespace Eagle
{

	class EAGLE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void onAttach() override;
		void onDetach() override;
		void onUpdate() override;
		void onEvent(Event& e) override;

	private:
		float dt;
		//GLFWwindow* win;

	};
}


