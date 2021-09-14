#pragma once
#include "pch.h"

#include "Core/Core.h"


namespace Eagle
{
	enum class EventType
	{
		None=0,
		WindowClose, WindowResize, WindowFocus, WindowUnfocus,
		KeyDown, KeyUp,
		MouseButtonDown, MouseButtonUp, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None=0,
		EventApplication	= (1 << 0),
		EventInput			= (1 << 1),
		EventKeyboard		= (1 << 2),
		EventMouse			= (1 << 3),
		EventMouseButton	= (1 << 4)
	};

	class EAGLE_API Event
	{
	public:
		virtual const char* getName() const = 0;
		virtual int getCategory() const = 0;
		virtual EventType getType() const = 0;

		virtual std::string toString() const { return getName(); }
		inline bool isInCategory(EventCategory category) { return getCategory() & category; }
		
		bool handled = false;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& event) { return os << event.toString(); }

	class EventDispatcher
	{
		template<typename T>
		using EventFunc = std::function<bool(T&)>; // some function to handle the event
	public:
		EventDispatcher(Event& _event) : event(_event) {}

		template<typename T>
		bool dispatch(EventFunc<T> func) 
		{
			if (event.getType() == T::getEventType())
			{
				event.handled = func(*(T*)&event);
				return true;
			}

			return false;
		}
	private:
		Event& event;
	};


}