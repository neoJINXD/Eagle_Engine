#pragma once
#include "pch.h"

namespace Eagle
{
	// ? do i need this here?
	enum RenderType {
		TRIANGLES = 0,
		WIREFRAME,
	};

	class EAGLE_API Renderer
	{
	public:
		virtual ~Renderer() = default;

		virtual void startFrame() const = 0;
		virtual void endFrame() const = 0;

		static Renderer* create();
	protected:
		// disallow making of a default renderer
		Renderer() = default;
	};
}

