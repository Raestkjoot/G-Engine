#include "GameObject.h"

#include <iostream>

GameObject::GameObject(const std::string& name) : 
    name(name), 
    transform(new Transform()) , 
    sprite(new Sprite()) {
}

GameObject::GameObject(GameObject&& other) {
    name = other.name;
    transform = other.transform;
    sprite = other.sprite;

    other.transform = nullptr;
    other.sprite = nullptr;
}