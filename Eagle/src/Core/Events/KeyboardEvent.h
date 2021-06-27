#pragma once

#include "Event.h"

namespace Eagle
{

	class EAGLE_API KeyEvent : public Event
	{
	public:
		[[nodiscard]] inline auto GetKeyCode() const -> int { return m_KeyCode; }

		[[nodiscard]] virtual auto GetCategory() const -> int override { return EventCategory::EventKeyboard | EventCategory::EventInput; }

		[[nodiscard]] auto ToString() const -> std::string override
		{
			std::stringstream ss;
			ss << GetName() << " - Code: " << m_KeyCode;
			return ss.str();
		}

	protected:
		explicit KeyEvent(const int keyCode) : m_KeyCode(keyCode) {}

		int m_KeyCode;
	};

	// TODO should handle key holding?
	class EAGLE_API KeyDownEvent final : public KeyEvent
	{
	public:
		explicit KeyDownEvent(const int keyCode,const bool repeated) : KeyEvent(keyCode), m_Repeated(repeated) {}

		inline static auto GetEventType() -> EventType { return EventType::KeyDown; }

		[[nodiscard]] virtual auto GetType() const -> EventType override { return GetEventType(); }
		[[nodiscard]] virtual auto GetName() const -> const char* override { return "Event::KeyDown"; }

		[[nodiscard]] auto ToString() const -> std::string override
		{
			std::stringstream ss;
			ss << GetName() << " - Code: " << m_KeyCode << ", isRepeated: " << m_Repeated;
			return ss.str();
		}

	private:
		bool m_Repeated;
	};
	
	class EAGLE_API KeyUpEvent final : public KeyEvent
	{
	public:
		explicit KeyUpEvent(const int keyCode) : KeyEvent(keyCode) {}

		inline static auto GetEventType() -> EventType { return EventType::KeyUp; }

		[[nodiscard]] virtual auto GetType() const -> EventType override { return GetEventType(); }
		[[nodiscard]] virtual auto GetName() const -> const char* override { return "Event::KeyUp"; }

	};

}
