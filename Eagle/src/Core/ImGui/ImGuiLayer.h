#pragma once
// TODO needs to be implemented to work with vulkan
#if 0
#include "Core/Layer.h"

namespace Eagle
{

	class EAGLE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& e) override;

	private:
		float dt;
		//GLFWwindow* win;

	};
}

#endif
