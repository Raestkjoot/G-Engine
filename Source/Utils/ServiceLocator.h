#pragma once

#include <cassert>

class Application;

class ServiceLocator {
public:
    static Application* GetApplication() {
        assert(_application != nullptr);
        return _application;
    }
    static void SetApplication(Application* application);

private:
    static Application* _application;
};