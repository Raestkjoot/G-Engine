#include "SceneLoader.h"

#include "Scene.h"

#include <fstream>
#include <iostream>
#include <format>
#include <charconv>

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
                        go->transform->position[i] = StrToFloat(str);
                    }
                    str.clear();
                    sceneFile >> str;
                }
                else if (str == "rotation") {
                    for (int i = 0; i < 3; ++i) {
                        str.clear();
                        sceneFile >> str;
                        go->transform->rotation[i] = StrToFloat(str);
                    }
                    str.clear();
                    sceneFile >> str;
                }
                else if (str == "scale") {
                    for (int i = 0; i < 3; ++i) {
                        str.clear();
                        sceneFile >> str;
                        go->transform->scale[i] = StrToFloat(str);
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
            // TODO: Add sprite component
        }

        str.clear();
    }

    return scene;
}

std::string SceneLoader::SerializeScene(Scene* scene) {
    std::string serializedData;
    char floatString[30];

    for (auto& go : scene->GetAllGameObjects()) {
        serializedData += "GameObject\n";
        serializedData += "\tname " + go.name + "\n";
        
        serializedData += "\tTransform\n";
        serializedData += "\t\tposition " + std::format("{} {} {}\n", 
            go.transform->position.x,
            go.transform->position.y,
            go.transform->position.z);
        serializedData += "\t\trotation " + std::format("{} {} {}\n", 
            go.transform->rotation.x,
            go.transform->rotation.y,
            go.transform->rotation.z);
        serializedData += "\t\tscale " + std::format("{} {} {}\n", 
            go.transform->scale.x,
            go.transform->scale.y,
            go.transform->scale.z);

        serializedData += "\tSprite\n";
    }

    return serializedData;
}

float SceneLoader::StrToFloat(const std::string& str) {
    // We use std::from_chars because it is locale-independent and uses the default ("C") locale, meaning '.' is used for the decimal point.
    // Other formatting functions, such as atof, can expect ',' for the decimal point.
    // std::from_chars should also be the fastest possible implementation, since it ignores most formatting policies.
    float val;
    std::from_chars(str.data(), str.data() + str.size(), val);
    return val;
}