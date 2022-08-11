#pragma once

#include "../../pch.hpp"
#include "../../core/TypeId.hpp"
#include "Mouse.hpp"

namespace SAGA {
    class MouseWheelEvent : public MouseEvent {
    public:
        MouseWheelEvent() : MouseEvent(TypeID<MouseWheelEvent>()) {}
        virtual ~MouseWheelEvent() override = default;
        
        std::string GetName() const override { return "MouseWheelEvent"; }
        std::string ToString() const override { return "MouseWheelEvent"; }
    };
}