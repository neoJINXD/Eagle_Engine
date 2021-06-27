#pragma once

#include "Core/Window.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Eagle
{
	class VulkanWindow final : public Window
	{
	public:
		explicit VulkanWindow(const std::string& _title = "Vulkan Window", unsigned int _width = 1280, unsigned int _height = 720);
		virtual ~VulkanWindow();

		auto Update() -> void override;

		[[nodiscard]] auto GetWidth() const -> unsigned int override { return data.width; }
		[[nodiscard]] auto GetHeight() const -> unsigned int override { return data.height; }

		auto SetEventCallback(const EventCallback& _callback) -> void override { data.callback = _callback; }


		auto SetVSync(bool enabled) -> void override;
		[[nodiscard]] auto GetVSync() const -> bool override;

		[[nodiscard]] auto GetWindow() const -> void* override { return window; }

	private:
		GLFWwindow* window;

		struct WindowData final
		{
			std::string title;
			unsigned int width, height;
			bool vSync;
			EventCallback callback;
		};

		WindowData data;

	};

}