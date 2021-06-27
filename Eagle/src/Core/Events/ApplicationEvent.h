#pragma once

#include "Event.h"

namespace Eagle
{
	class EAGLE_API WindowCloseEvent final : public Event
	{
	public:
		WindowCloseEvent() = default;

		inline static auto GetEventType() -> EventType { return EventType::WindowClose; }

		[[nodiscard]] virtual auto GetType() const -> EventType override { return GetEventType(); }
		[[nodiscard]] virtual auto GetCategory() const -> int override { return EventCategory::EventApplication; }
		[[nodiscard]] virtual auto GetName() const -> const char* override { return "Event::WindowClose"; }
	};

	class EAGLE_API WindowResizeEvent final : public Event
	{
	public:
		WindowResizeEvent(const unsigned int width, const unsigned int height) :
			m_Width(width), m_Height(height) {}

		inline static auto GetEventType() -> EventType { return EventType::WindowResize; }

		[[nodiscard]] virtual auto GetType() const -> EventType override { return GetEventType(); }
		[[nodiscard]] virtual auto GetCategory() const -> int override { return EventCategory::EventApplication; }
		[[nodiscard]] virtual auto GetName() const -> const char* override { return "Event::WindowResize"; }

		[[nodiscard]] auto ToString() const -> std::string override
		{ 
			std::stringstream ss;
			ss << GetName() << " - " << m_Width << "x" << m_Height;
			return ss.str(); 
		}

	private:
		unsigned int m_Width, m_Height;
	};

	class EAGLE_API WindowFocusEvent final : public Event
	{
	public:
		WindowFocusEvent() = default;

		inline static auto GetEventType() -> EventType { return EventType::WindowFocus; }

		[[nodiscard]] virtual auto GetType() const -> EventType override { return GetEventType(); }
		[[nodiscard]] virtual auto GetCategory() const -> int override { return EventCategory::EventApplication; }
		[[nodiscard]] virtual auto GetName() const -> const char* override { return "Event::WindowFocus"; }
	};


	class EAGLE_API WindowUnfocusEvent final : public Event
	{
	public:
		WindowUnfocusEvent() = default;

		inline static auto GetEventType() -> EventType { return EventType::WindowUnfocus; }

		[[nodiscard]] virtual auto GetType() const -> EventType override { return GetEventType(); }
		[[nodiscard]] virtual auto GetCategory() const -> int override { return EventCategory::EventApplication; }
		[[nodiscard]] virtual auto GetName() const -> const char* override { return "Event::WindowUnfocus"; }
	};
}