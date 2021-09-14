#pragma once

#include "Event.h"

namespace Eagle
{
	class EAGLE_API MouseEvent : public Event
	{
		virtual int getCategory() const override { return EventCategory::EventMouse | EventCategory::EventInput; }
	};

	class EAGLE_API MouseButtonEvent : public MouseEvent
	{
	public:
		inline int getButtonID() const { return button; }

		//virtual int getCategory() const override { return EventCategory::EventMouse | EventCategory::EventInput; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << " - ButtonID: " << button;
			return ss.str();
		}

	protected:
		MouseButtonEvent(int buttonID) : button(buttonID) {}

		int button;
	};

	class EAGLE_API MouseButtonDownEvent : public MouseButtonEvent
	{
	public:
		MouseButtonDownEvent(int buttonID) : MouseButtonEvent(buttonID) {}

		inline static EventType getEventType() { return EventType::MouseButtonDown; }

		virtual EventType getType() const override { return getEventType(); }
		virtual const char* getName() const override { return "Event::MouseButtonDown"; }
	};
	
	class EAGLE_API MouseButtonUpEvent : public MouseButtonEvent
	{
	public:
		MouseButtonUpEvent(int buttonID) : MouseButtonEvent(buttonID) {}

		inline static EventType getEventType() { return EventType::MouseButtonUp; }

		virtual EventType getType() const override { return getEventType(); }
		virtual const char* getName() const override { return "Event::MouseButtonUp"; }
	};

	class EAGLE_API MouseMovedEvent : public MouseEvent
	{
	public:
		MouseMovedEvent(float _mouseX, float _mouseY) :
			mouseX(_mouseX), mouseY(_mouseY) {}

		inline float getX() const { return mouseX; }
		inline float getY() const { return mouseY; }

		inline static EventType getEventType() { return EventType::MouseMoved; }

		virtual EventType getType() const override { return getEventType(); }
		//virtual int getCategory() const override { return EventCategory::EventMouse | EventCategory::EventInput; }
		virtual const char* getName() const override { return "Event::MouseMoved"; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << " - x: " << mouseX << ", y: " << mouseY;
			return ss.str();
		}
	private:
		float mouseX, mouseY;
	};
	
	class EAGLE_API MouseScrollEvent : public MouseEvent
	{
	public:
		MouseScrollEvent(float _deltaX, float _deltaY) :
			deltaX(_deltaX), deltaY(_deltaY) {}

		inline float getDeltaX() const { return deltaX; }
		inline float getDeltaY() const { return deltaY; }

		inline static EventType getEventType() { return EventType::MouseScrolled; }

		virtual EventType getType() const override { return getEventType(); }
		//virtual int getCategory() const override { return EventCategory::EventMouse | EventCategory::EventInput; }
		virtual const char* getName() const override { return "Event::MouseScroll"; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << " - dx: " << deltaX << ", dy: " << deltaY;
			return ss.str();
		}
	private:
		float deltaX, deltaY;
	};

}