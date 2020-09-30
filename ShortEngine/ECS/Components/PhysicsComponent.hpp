//
//  PhysicsComponent.hpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 29/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef PhysicsComponent_hpp
#define PhysicsComponent_hpp

#include <stdio.h>

#include "PVector.hpp"
#include "TransformComponent.hpp"

class PhysicsComponent
{
public:
    
    PhysicsComponent(float mass): _mass(mass)
    {
    }
    
    void applyForce(PVector force)
    {
        if (_mass != 0) // _mass == 0 -> immovable object
        {
            // F / m = a
            force /= _mass;
            
            // Add force to existing acceleration
            _acceleration += force;
        }
    }
    
    void simulate(TransformComponent* transform, Uint32& timestep)
    {
        // Add acceleration to velocity
        _velocity += _acceleration;
        
        // Apply timestep
        _acceleration *= (timestep/100.0f);
        
        // Add velocity to location
        transform->position += _velocity;
        
        // Reset simulation
        _acceleration *= 0.0f;
        
    }
    
    
private:
    float _mass{0};
    PVector _velocity{0,0};
    PVector _force{0,0};
    PVector _acceleration{0,0};
};

#endif /* PhysicsComponent_hpp */
