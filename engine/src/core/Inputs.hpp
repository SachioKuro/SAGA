#pragma once

#include "../pch.hpp"
#include "event/EventDispatcher.hpp"
#include "service/Locator.hpp"
#include "event/system/SystemQuitEvent.hpp"

namespace SAGA {
    class SAGA_API Inputs {
    public:
        static const uint8_t* keyboard;

        Inputs();

        void InitInputs(SDL_Window*);
        void DispatchInputEvents();
        bool IsKey(int);
    private:
        EventDispatcherService* m_eventDispatcher;
    };
}