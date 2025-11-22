#pragma once

#include "Application.h"
#include <filesystem>

class EngineApplication : public Application {
public:
    void Run() override;
    std::string GetProjectPath();

private:
    std::filesystem::path _projectPath;
};
