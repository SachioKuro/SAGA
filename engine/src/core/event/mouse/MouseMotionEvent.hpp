#pragma once

#include "../../../pch.hpp"
#include "../../TypeId.hpp"
#include "Mouse.hpp"

namespace SAGA {
    class MouseMotionEvent : public MouseEvent {
    public:
        MouseMotionEvent() : MouseEvent(TypeID<MouseMotionEvent>()) {}
        virtual ~MouseMotionEvent() override = default;
        
        std::string GetName() const override { return "MouseMotionEvent"; }
        std::string ToString() const override { return "MouseMotionEvent"; }
    };
}