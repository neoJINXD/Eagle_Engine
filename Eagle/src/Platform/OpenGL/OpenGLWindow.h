#pragma once
// TODO still needs to be refactored

#if 0
#include "Core/Window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Eagle
{
	class OpenGLWindow : public Window
	{
	public:
		OpenGLWindow(const std::string& _title = "OpenGL Window", unsigned int _width = 1280, unsigned int _height = 720);
		virtual ~OpenGLWindow();

		void Update() override;

		inline unsigned int GetWidth() const override { return data.width; }
		inline unsigned int GetHeight() const override { return data.height; }

		inline void SetEventCallback(const EventCallback& _callback) override { data.callback = _callback; }


		void SetVSync(bool enabled) override;
		bool GetVSync() const override;

		inline void* GetWindow() const override { return window; }
		
	private:
		GLFWwindow* window;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool vSync;
			EventCallback callback;
		};

		WindowData data;

	};

}

#endif