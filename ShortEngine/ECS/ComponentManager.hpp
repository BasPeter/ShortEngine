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
#include <set>
#include <algorithm>

#include "Game.hpp"
#include "EntityManager.hpp"
#include "Components.hpp"
#include "SpriteSheet.hpp"

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
    void Emplace(Entity* entity, Args... args);
    void Remove(Entity* entity);
    
    T* GetComponent(unsigned id);
    std::vector<T>& GetView() { return _components; };
    
    template <typename G>
    std::vector<std::pair<T*, G*>> Group();
    
private:
    std::unordered_map<unsigned, unsigned> _map;
    std::vector<T*> _components{};
    
    unsigned int idx;
};

#endif /* ComponentManager_hpp */
