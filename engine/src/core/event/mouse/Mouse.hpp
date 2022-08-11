#pragma once

#include "../../../pch.hpp"
#include "../Event.hpp"

namespace SAGA {
    class MouseEvent : public Event {
    public:
        MouseEvent(EventId id) : Event(id) {}
        virtual ~MouseEvent() override = default;
        
        EventType GetType() const override { return EventType::MouseEvent; }
    };
}
