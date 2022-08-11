#pragma once

#include "../../pch.hpp"
#include "../../core/TypeId.hpp"
#include "Mouse.hpp"

namespace SAGA {
    class MouseDownEvent : public MouseEvent {
    public:
        MouseDownEvent(uint8_t btn) : MouseEvent(TypeID<MouseDownEvent>()), m_btn(btn) {}
        virtual ~MouseDownEvent() override = default;
        
        std::string GetName() const override { return "MouseDownEvent"; }
        std::string ToString() const override { return "MouseDownEvent"; }
    protected:
        uint8_t m_btn;
    };
}