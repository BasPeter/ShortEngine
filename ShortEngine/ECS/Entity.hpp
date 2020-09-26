//
//  Entity.hpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 26/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include <iostream>

class Entity
{
public:
    
    Entity(unsigned int id);
    ~Entity();
    Entity(Entity const& source);
    
    const unsigned getId() { return _id; };
    
private:
    const unsigned int _id{0};
};

#endif /* Entity_hpp */
