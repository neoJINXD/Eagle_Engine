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
		virtual ~Event() = default;
		[[nodiscard]] virtual const char* GetName() const = 0;
		[[nodiscard]] virtual int GetCategory() const = 0;
		[[nodiscard]] virtual EventType GetType() const = 0;

		[[nodiscard]] virtual std::string ToString() const { return GetName(); }
		[[nodiscard]] inline bool IsInCategory(const EventCategory category) const { return GetCategory() & category; }
		
		bool handled = false;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& event) { return os << event.ToString(); }

	class EventDispatcher
	{
		template<typename T>
		using EventFunc = std::function<bool(T&)>; // some function to handle the event
	public:
		explicit EventDispatcher(Event& event) : m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFunc<T> func) 
		{
			if (m_Event.GetType() == T::GetEventType())
			{
				m_Event.handled = func(*reinterpret_cast<T*>(&m_Event));
				return true;
			}

			return false;
		}
	private:
		Event& m_Event;
	};


}