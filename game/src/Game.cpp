#include <core/Entry.hpp>


SAGA::Application* SAGA::CreateApp() {
    SAGA::AppConfig config;
    config.extent = {800, 600};
    config.title = "SAGA Sandbox";
    config.icon = "";
    config.version = {1, 0, 0};
    return new SAGA::Application(config);
}