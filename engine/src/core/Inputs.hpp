#pragma once

#include "pch.hpp"
#include "event/EventDispatcher.hpp"
#include "service/Locator.hpp"
#include "event/system/SystemQuitEvent.hpp"
#include "event/keyboard/KeyDownEvent.hpp"
#include "event/keyboard/KeyUpEvent.hpp"
#include "event/mouse/MouseDownEvent.hpp"
#include "event/mouse/MouseUpEvent.hpp"
#include "event/mouse/MouseMotionEvent.hpp"
#include "event/mouse/MouseWheelEvent.hpp"


namespace SAGA {
    struct MouseState {
        glm::vec2 position;
        glm::vec2 motion;
        glm::vec2 wheel;
        std::bitset<7> buttons;
    };

    class SAGA_API Inputs {
    public:
        static const uint8_t* keyboard;

        Inputs();

        void InitInputs(SDL_Window*);
        void DispatchInputEvents();

        bool IsKeyDown(int);

        glm::vec2 GetMousePosition() const;
        glm::vec2 GetMouseMotion() const;
        glm::vec2 GetMouseWheel() const;
        bool IsMouseButtonDown(int) const;
    private:
        static MouseState s_mouseState;

        EventDispatcherService* m_eventDispatcher;
    };
}