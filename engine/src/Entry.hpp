#pragma once

#include "Application.hpp"

extern SAGA::Application* SAGA::CreateApp();

int main(int argc, char** argv) {
    auto app = SAGA::CreateApp();
    app->Run();
    delete app;
    return 0;
}