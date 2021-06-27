#pragma once

#include "Event.h"

namespace Eagle
{
	class EAGLE_API MouseEvent : public Event
	{
		[[nodiscard]] virtual auto GetCategory() const -> int override { return EventCategory::EventMouse | EventCategory::EventInput; }
	};

	class EAGLE_API MouseButtonEvent : public MouseEvent
	{
	public:
		[[nodiscard]] inline auto GetButtonId() const -> int { return m_Button; }

		//virtual int getCategory() const override { return EventCategory::EventMouse | EventCategory::EventInput; }

		[[nodiscard]] auto ToString() const -> std::string override
		{
			std::stringstream ss;
			ss << GetName() << " - ButtonID: " << m_Button;
			return ss.str();
		}

	protected:
		explicit MouseButtonEvent(const int buttonId) : m_Button(buttonId) {}

		int m_Button;
	};

	class EAGLE_API MouseButtonDownEvent final : public MouseButtonEvent
	{
	public:
		explicit MouseButtonDownEvent(const int buttonId) : MouseButtonEvent(buttonId) {}

		inline static auto GetEventType() -> EventType { return EventType::MouseButtonDown; }

		[[nodiscard]] virtual auto GetType() const -> EventType override { return GetEventType(); }
		[[nodiscard]] virtual auto GetName() const -> const char* override { return "Event::MouseButtonDown"; }
	};
	
	class EAGLE_API MouseButtonUpEvent final : public MouseButtonEvent
	{
	public:
		explicit MouseButtonUpEvent(const int buttonId) : MouseButtonEvent(buttonId) {}

		inline static EventType GetEventType() { return EventType::MouseButtonUp; }

		[[nodiscard]] virtual auto GetType() const -> EventType override { return GetEventType(); }
		[[nodiscard]] virtual auto GetName() const -> const char* override { return "Event::MouseButtonUp"; }
	};

	class EAGLE_API MouseMovedEvent final : public MouseEvent
	{
	public:
		MouseMovedEvent(const float mouseX, const float mouseY) :
			m_MouseX(mouseX), m_MouseY(mouseY) {}

		[[nodiscard]] inline auto GetX() const -> float { return m_MouseX; }
		[[nodiscard]] inline auto GetY() const -> float { return m_MouseY; }

		inline static auto GetEventType() -> EventType { return EventType::MouseMoved; }

		[[nodiscard]] virtual auto GetType() const -> EventType override { return GetEventType(); }
		//virtual int getCategory() const override { return EventCategory::EventMouse | EventCategory::EventInput; }
		[[nodiscard]] virtual auto GetName() const -> const char* override { return "Event::MouseMoved"; }

		[[nodiscard]] auto ToString() const -> std::string override
		{
			std::stringstream ss;
			ss << GetName() << " - x: " << m_MouseX << ", y: " << m_MouseY;
			return ss.str();
		}
	private:
		float m_MouseX, m_MouseY;
	};
	
	class EAGLE_API MouseScrollEvent final : public MouseEvent
	{
	public:
		MouseScrollEvent(float _deltaX, float _deltaY) :
			m_DeltaX(_deltaX), m_DeltaY(_deltaY) {}

		[[nodiscard]] inline auto GetDeltaX() const -> float { return m_DeltaX; }
		[[nodiscard]] inline auto GetDeltaY() const -> float { return m_DeltaY; }

		inline static auto GetEventType() -> EventType { return EventType::MouseScrolled; }

		[[nodiscard]] virtual auto GetType() const -> EventType override { return GetEventType(); }
		//virtual int getCategory() const override { return EventCategory::EventMouse | EventCategory::EventInput; }
		[[nodiscard]] virtual auto GetName() const -> const char* override { return "Event::MouseScroll"; }

		[[nodiscard]] auto ToString() const -> std::string override
		{
			std::stringstream ss;
			ss << GetName() << " - dx: " << m_DeltaX << ", dy: " << m_DeltaY;
			return ss.str();
		}
	private:
		float m_DeltaX, m_DeltaY;
	};

}