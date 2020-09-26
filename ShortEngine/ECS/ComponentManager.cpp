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

template ComponentManager<TransformComponent>::ComponentManager();

template <typename T>
ComponentManager<T>::~ComponentManager()
{
    
}

template ComponentManager<TransformComponent>::~ComponentManager();


template <typename T>
template <typename... Args>
void ComponentManager<T>::Emplace(Entity& entity, Args... args)
{
    // Create new component and add to _component list
    T newComponent = T(args...);
    _components.push_back(std::move(newComponent));
    
    // Add index to lookup table and increment index
    _map[entity._id] = idx++;
}

template <typename T>
void ComponentManager<T>::Remove(Entity entity) {
    
    auto idx = _map[entity._id];
    
}

template void ComponentManager<TransformComponent>::Emplace(Entity& entity, float x, float y, float w, float h, float r);

