#pragma once

#include "pch.h"

#include "Core/Core.h"
#include "Core/Events/Event.h"

namespace Eagle
{
   class EAGLE_API Window
   {
    public:
      using EventCallback = std::function<void(Event&)>;

      virtual ~Window() = default;

      virtual void update() = 0;

      virtual unsigned int getWidth() const = 0;
      virtual unsigned int getHeight() const = 0;

      virtual void setEventCallback(const EventCallback& _callback) = 0;

      virtual void setVSync(bool enabled) = 0;
      virtual bool getVSync() const = 0;

      virtual void* getWindow() const = 0;

      static Window* create();
   };
}