//
//  EntityManager.cpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 24/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#include "EntityManager.hpp"

#include <typeinfo>

EntityManager* EntityManager::_registry = nullptr;

EntityManager::EntityManager() {}

EntityManager::~EntityManager() {}

EntityManager* EntityManager::CreateRegistry()
{
    _registry = new EntityManager();
    return EntityManager::_registry;
}

void EntityManager::DestroyRegistry() {
    delete _registry;
}

Entity& EntityManager::Create()
{
    _entities.emplace_back(_idx);
    return _entities[_idx++];
}

Entity& EntityManager::GetEntity(unsigned int idx)
{
    return _entities[idx];
}

template <typename T, typename... Args>
void EntityManager::Emplace(Entity& entity, Args... args)
{
    // Get correct component manager to use
    ComponentManager<T>* manager = dynamic_cast<ComponentManager<T>*>(GetComponentManager<T>());
    
    // Create component with component manager
    manager->Emplace(entity, args...);
}

// Explicit instatiation
template void EntityManager::Emplace<TransformComponent>(Entity& entity, float x, float y, float w, float h, float r);


template <typename T>
ComponentManagerInstance* EntityManager::GetComponentManager()
{
    auto manager = _managers[typeid(T).name()];
    if (manager == nullptr)
    {
//        auto newManager = new ComponentManager<T>();
        manager = std::make_shared<ComponentManager<T>>();
//        manager = newptr;
        _managers[typeid(T).name()] = manager;
    }
    
    return manager.get();
}

template ComponentManagerInstance* EntityManager::GetComponentManager<TransformComponent>();
