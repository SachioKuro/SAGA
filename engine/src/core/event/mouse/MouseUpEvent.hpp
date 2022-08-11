#pragma once

#include "../../../pch.hpp"
#include "../../TypeId.hpp"
#include "Mouse.hpp"

namespace SAGA {
    class MouseUpEvent : public MouseEvent {
    public:
        MouseUpEvent(uint8_t btn) : MouseEvent(TypeID<MouseUpEvent>()), m_btn(btn) {}
        virtual ~MouseUpEvent() override = default;
        
        std::string GetName() const override { return "MouseUpEvent"; }
        std::string ToString() const override { return "MouseUpEvent"; }
    protected:
        uint8_t m_btn;
    };
}