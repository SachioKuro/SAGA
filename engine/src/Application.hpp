#pragma once

#include "pch.hpp"
#include "core/Extent.hpp"
#include "core/Version.hpp"
#include "core/Inputs.hpp"

#include "service/EventDispatcherService.hpp"
#include "event/EventDispatcher.hpp"
#include "event/Event.hpp"
#include "service/Locator.hpp"

namespace SAGA {
    struct SAGA_API AppConfig {
        Extent extent;
        std::string title;
        std::string icon;
        Version version;
    };

    class SAGA_API Application {
    public:
        Application(const AppConfig& appConfig): m_appConfig(appConfig) {
            Init();
        };
        virtual ~Application() = default;
        Application(const Application&) = delete;
        Application& operator=(const Application&) = delete;
        Application(Application&&) = delete;
        Application& operator=(Application&&) = delete;
        void Init();
        void Run();

        static void OnExit(const Event*);
    protected:
        AppConfig m_appConfig;
        
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        Inputs* m_inputs;

        EventDispatcher* m_eventDispatcher;

    };

    Application* CreateApp();
}