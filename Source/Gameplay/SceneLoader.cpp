#include "SceneLoader.h"

#include "Scene.h"

#include <fstream>
#include <iostream>

Scene* SceneLoader::LoadScene(const std::string& filename) {
    Scene* scene = new Scene();

    std::string str;
    std::ifstream sceneFile(filename);
    GameObject* go = nullptr;

    while (sceneFile >> str) {
        if (str == "GameObject") {
            str.clear();
            sceneFile >> str;
            if (!sceneFile.eof() && str == "name") {
                str.clear();
                sceneFile >> str;
                go = scene->CreateGameObject(str);
            }
            else {
                go = scene->CreateGameObject("GameObject");
            }
        }
        if (str == "Transform") {
            str.clear();
            sceneFile >> str;
            while (true)
            {
                if (str == "position") {
                    for (int i = 0; i < 3; ++i) {
                        str.clear();
                        sceneFile >> str;
                        go->transform->position[i] = stof(str);
                    }
                    str.clear();
                    sceneFile >> str;
                }
                else if (str == "rotation") {
                    for (int i = 0; i < 3; ++i) {
                        str.clear();
                        sceneFile >> str;
                        go->transform->rotation[i] = stof(str);
                    }
                    str.clear();
                    sceneFile >> str;
                }
                else if (str == "scale") {
                    for (int i = 0; i < 3; ++i) {
                        str.clear();
                        sceneFile >> str;
                        go->transform->scale[i] = stof(str);
                    }
                    str.clear();
                    sceneFile >> str;
                }
                else {
                    break;
                }
            }
        }
        if (str == "Sprite") {
            std::cout << str << std::endl;
        }

        str.clear();
    }

    return scene;
}