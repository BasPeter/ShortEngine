//
//  ComponentManager.hpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 25/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef ComponentManager_hpp
#define ComponentManager_hpp

#include <stdio.h>
#include <unordered_map>
#include <vector>

#include "EntityManager.hpp"
#include "TransformComponent.hpp"

// Forward declaration Entity
struct Entity;

struct ComponentManagerInstance
{
    virtual ~ComponentManagerInstance() = default;
};

template <typename T>
class ComponentManager: public ComponentManagerInstance
{
public:
    ComponentManager();
    ~ComponentManager();
    
    template <typename... Args>
    void Emplace(Entity& entity, Args... args);
    void Remove(Entity entity);
    
    std::vector<T>& GetView() { return _components; };
    
private:
    std::unordered_map<unsigned, unsigned> _map;
    std::vector<T> _components{};
    
    unsigned int idx;
};

#endif /* ComponentManager_hpp */
