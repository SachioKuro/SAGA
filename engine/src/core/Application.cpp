#include "Application.hpp"

namespace SAGA {
    static bool s_isRunning = true;

    void Application::Init() {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            SAGA_ERROR("SDL_Init failed: %s", SDL_GetError());
            return;
        }
        if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) < 0) {
            SAGA_ERROR("IMG_Init failed: %s", IMG_GetError());
            return;
        }
        if (TTF_Init() < 0) {
            SAGA_ERROR("TTF_Init failed: %s", TTF_GetError());
            return;
        }
        if (
            Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) < 0 ||
            Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024)
        ) {
            SAGA_ERROR("Mix_Init failed: %s", Mix_GetError());
            return;
        }

        auto windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;
        m_window = SDL_CreateWindow(
            m_appConfig.title.c_str(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            m_appConfig.extent.width, m_appConfig.extent.height,
            windowFlags
        );

        if (!m_window) {
            SAGA_ERROR("SDL_CreateWindow failed: %s", SDL_GetError());
            return;
        }

        auto rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
        m_renderer = SDL_CreateRenderer(m_window, -1, rendererFlags);

        if (!m_renderer) {
            SAGA_ERROR("SDL_CreateRenderer failed: %s", SDL_GetError());
            return;
        }


        m_eventDispatcher = new EventDispatcher();
        Locator::SetService<EventDispatcherService>(m_eventDispatcher);

        m_eventDispatcher->RegisterCallback(EventType::SystemEvent, std::bind(Application::OnExit, std::placeholders::_1));
        
        m_inputs = new Inputs();
        m_inputs->InitInputs(m_window);

        glm::vec3 vector = glm::vec3(-1.0f, 7.0f, 10.0f);
        SAGA_INFO(std::to_string(vector.length()));
    }

    void Application::Run() {
        while(s_isRunning) {
            SDL_Event event;
            m_inputs->DispatchInputEvents();
            if (m_inputs->IsKey(SDL_SCANCODE_ESCAPE)) {
                s_isRunning = false;
            }
            if (m_inputs->IsKey(SDL_SCANCODE_F)) {
                SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
            }
            if (m_inputs->IsKey(SDL_SCANCODE_A)) {
                SAGA_INFO("Hello World!");
            }
            SDL_RenderClear(m_renderer);
            SDL_RenderPresent(m_renderer);
        }

        SDL_Quit();
        IMG_Quit();
        TTF_Quit();
        Mix_Quit();
    }

    void Application::OnExit(const Event* event) {
        s_isRunning = false;
        event->IsHandled();
    }
}