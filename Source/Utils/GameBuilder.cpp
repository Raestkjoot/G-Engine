#include "GameBuilder.h"

#include "Utils/ServiceLocator.h"
#include "EngineApplication.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <spawn.h>
#include <sys/wait.h>

extern char** environ;

void GameBuilder::BuildGame() {
    const char* cmd = "mkdir TestingExport";
    pid_t pid;
    std::string projectPath = static_cast<EngineApplication*>(ServiceLocator::GetApplication())->GetProjectPath();
    char *argv[] = {const_cast<char*>("mkdir"), const_cast<char*>(projectPath.append("/TestingExport").c_str()), nullptr};
    int status;
    std::cout << "running command " << cmd << std::endl;
    status = posix_spawn(&pid, "/bin/mkdir", nullptr, nullptr, argv, environ);

    if (status == 0) {
        printf("Child pid: %i\n", pid);
        do {
          if (waitpid(pid, &status, 0) != -1) {
            printf("Child status %d\n", WEXITSTATUS(status));
          } else {
            perror("waitpid");
            exit(1);
          }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    } else {
        printf("posix_spawn: %s\n", strerror(status));
    }

//    status = posix_spawn(&pid, "bin/" nullptr, nullptr, 
}
