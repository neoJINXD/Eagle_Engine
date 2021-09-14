#pragma once

#include "Event.h"

namespace Eagle
{

	class EAGLE_API KeyEvent : public Event
	{
	public:
		inline int getKeyCode() const { return keyCode; }

		virtual int getCategory() const override { return EventCategory::EventKeyboard | EventCategory::EventInput; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << " - Code: " << keyCode;
			return ss.str();
		}

	protected:
		KeyEvent(int _keyCode) : keyCode(_keyCode) {}

		int keyCode;
	};

	// TODO should handle key holding?
	class EAGLE_API KeyDownEvent : public KeyEvent
	{
	public:
		KeyDownEvent(int _keyCode, bool _repeated) : KeyEvent(_keyCode), repeated(_repeated) {}

		inline static EventType getEventType() { return EventType::KeyDown; }

		virtual EventType getType() const override { return getEventType(); }
		virtual const char* getName() const override { return "Event::KeyDown"; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << " - Code: " << keyCode << ", isRepeated: " << repeated;
			return ss.str();
		}

	private:
		bool repeated;
	};
	
	class EAGLE_API KeyUpEvent : public KeyEvent
	{
	public:
		KeyUpEvent(int _keyCode) : KeyEvent(_keyCode) {}

		inline static EventType getEventType() { return EventType::KeyUp; }

		virtual EventType getType() const override { return getEventType(); }
		virtual const char* getName() const override { return "Event::KeyUp"; }

	};

}
