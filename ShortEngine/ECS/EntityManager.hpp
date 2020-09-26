//
//  EntityManager.hpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 24/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef EntityManager_hpp
#define EntityManager_hpp

#include <stdio.h>
#include <unordered_map>
#include <functional>
#include <iostream>

#include "ComponentManager.hpp"
#include "TransformComponent.hpp"
#include "Component.hpp"

struct ComponentManagerInstance;

struct Entity
{
    unsigned int _id;
    
    Entity(unsigned int id): _id(id)
    {
//        std::cout << "Entity Contructor Called" << std::endl;
    };
    ~Entity(){};
    
    Entity(Entity const& e)
    {
//        std::cout << "Entity Copy Constructor Called" << std::endl;
    }
    
    std::size_t operator() (const Entity& e) const
    {
        return std::hash<unsigned int>{}(e._id);
    }
};

class EntityManager
{
public:
    EntityManager();
    ~EntityManager();
    
    static EntityManager* CreateRegistry();
    static void DestroyRegistry();
    
    bool isAlive();
    
    // Create Component on Entity
    template <typename T, typename... Args>
    void Emplace(Entity&, Args... args);
    
    // Create and get Entity
    Entity& Create();
    Entity& GetEntity(unsigned int idx);
    std::vector<Entity>& GetEntities() { return _entities; };
        
    // Get Component Manager
    template <typename T>
    ComponentManagerInstance* GetComponentManager();
    
    
private:
    static EntityManager* _registry;
    
    unsigned int _idx{0};
    std::vector<Entity> _entities;
        
    std::unordered_map<const char*, std::shared_ptr<ComponentManagerInstance>> _managers;
};

#endif /* EntityManager_hpp */
