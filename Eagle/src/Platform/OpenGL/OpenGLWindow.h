#pragma once

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

		void update() override;

		inline unsigned int getWidth() const override { return data.width; }
		inline unsigned int getHeight() const override { return data.height; }

		inline void setEventCallback(const EventCallback& _callback) override { data.callback = _callback; }


		void setVSync(bool enabled) override;
		bool getVSync() const override;

		inline void* getWindow() const override { return window; }
		
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