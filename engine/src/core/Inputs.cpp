#include "Inputs.hpp"

namespace SAGA {
    const uint8_t* Inputs::keyboard = NULL;

    Inputs::Inputs() {  // : m_eventDispatcher(Locator::GetService<EventDispatcherService>()) {
        //InitInputs(Locator::GetService<SDL_Window>());
        m_eventDispatcher = Locator::GetService<EventDispatcherService>();
    }

    bool Inputs::IsKey(int key) {
        return keyboard[key];
    }

    void Inputs::InitInputs(SDL_Window* window) {
        keyboard = (uint8_t*)SDL_GetKeyboardState(NULL);
    }

    void Inputs::DispatchInputEvents() {
        static SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                m_eventDispatcher->PostEvent(new SystemQuitEvent());
                break;
            case SDL_MOUSEBUTTONDOWN:
                m_eventDispatcher->PostEvent(new MouseDownEvent(event.button.button));
                break;
            case SDL_MOUSEBUTTONUP:
                m_eventDispatcher->PostEvent(new MouseUpEvent(event.button.button));
                break;
            case SDL_MOUSEMOTION:
                m_eventDispatcher->PostEvent(new MouseMotionEvent());
                break;
            case SDL_MOUSEWHEEL:
                m_eventDispatcher->PostEvent(new MouseWheelEvent());
                break;
            case SDL_KEYDOWN:
                keyboard = SDL_GetKeyboardState(NULL);
                m_eventDispatcher->PostEvent(new KeyDownEvent(event.key.keysym.scancode));
                break;
            case SDL_KEYUP:
                keyboard = SDL_GetKeyboardState(NULL);
                m_eventDispatcher->PostEvent(new KeyUpEvent(event.key.keysym.scancode));
                break;
            }
        }
        m_eventDispatcher->Dispatch(EventType::SystemEvent);
    }
}