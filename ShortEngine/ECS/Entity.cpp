//
//  Entity.cpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 26/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity(unsigned int id): _id(id)
{
//    std::cout << "Entity Constructor Called" << std::endl;
}

Entity::~Entity()
{
//    std::cout << "Entity Destructor Called" << std::endl;
}

Entity::Entity(Entity const& source): _id(source._id)
{
//    std::cout << "Entity Copy Constructor Called" << std::endl;
}
