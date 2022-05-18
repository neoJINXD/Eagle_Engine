#pragma once
#include "Renderer.h"

namespace Eagle
{
	class OpenGLRenderer: public Renderer
	{
	public:
		OpenGLRenderer();
		virtual ~OpenGLRenderer();
		
		virtual void startFrame() const;
		virtual void endFrame() const;
	private:
		void checkGlErrors() const;
	};
}

