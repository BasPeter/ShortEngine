//
//  ComponentManager.cpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 25/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#include "ComponentManager.hpp"

template <typename T>
ComponentManager<T>::ComponentManager()
{
    
}

// Explicit instatiation
template ComponentManager<TransformComponent>::ComponentManager();
template ComponentManager<SpriteComponent>::ComponentManager();
template ComponentManager<AnimateComponent>::ComponentManager();

template <typename T>
ComponentManager<T>::~ComponentManager()
{
    
}

// Explicit instatiation
template ComponentManager<TransformComponent>::~ComponentManager();
template ComponentManager<SpriteComponent>::~ComponentManager();
template ComponentManager<AnimateComponent>::~ComponentManager();


template <typename T>
template <typename... Args>
void ComponentManager<T>::Emplace(Entity* entity, Args... args)
{
    // Create new component and add to _component list
    _components.emplace_back(new T(args...));
    
    // Add index to lookup table and increment index
    _map[entity->getId()] = idx++;
}

template <typename T>
void ComponentManager<T>::Remove(Entity* entity) {
    
    auto idx = _map[entity->getId()];
    
}

// Explicit instatiation
template void ComponentManager<TransformComponent>::Emplace(Entity* entity, float x, float y, float w, float h, float r);
template void ComponentManager<SpriteComponent>::Emplace(Entity* entity, const char*, int, int, int, int, int);
template void ComponentManager<AnimateComponent>::Emplace(Entity* entity, int, int, bool);


template <typename T>
T* ComponentManager<T>::GetComponent(unsigned int id)
{
    auto search = _map.find(id);
    if (search != _map.end())
    {
        return (_components[search->first]);
    }
    return nullptr;
}

template <typename T>
template <typename G>
std::vector<std::pair<T*, G*>> ComponentManager<T>::Group()
{
    std::vector<std::pair<T*, G*>> grouped_components;
    
    ComponentManager<G>* otherManager = dynamic_cast<ComponentManager<G>*>(Game::Registry->GetComponentManager<G>());
    G* otherComponent = nullptr;
    for (auto& [key, value] : _map)
    {
        otherComponent = otherManager->GetComponent(key);
        if (otherComponent != nullptr)
        {
            T* thisComponent = _components[key];
            std::pair<T*,G*> pair = std::make_pair(thisComponent, otherComponent);
            grouped_components.push_back(std::move(pair));
        }
    }
    
    return grouped_components;
}

template std::vector<std::pair<SpriteComponent*, TransformComponent*>> ComponentManager<SpriteComponent>::Group<TransformComponent>();
template std::vector<std::pair<SpriteComponent*, AnimateComponent*>> ComponentManager<SpriteComponent>::Group<AnimateComponent>();
