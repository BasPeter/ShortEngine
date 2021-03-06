//
//  TransformComponent.hpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 25/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef TransformComponent_hpp
#define TransformComponent_hpp

#include <iostream>

#include "PVector.hpp"

struct TransformComponent
{
    PVector position;
    float scale[2];
    float rotation;
    
    TransformComponent(float x, float y, float w, float h, float r): position(PVector{x, y})
    {
        scale[0] = w;
        scale[1] = h;
        rotation = r;
    };
        
    ~TransformComponent() { std::cout << "TransformComponent Destructor Called" << std::endl; };
    TransformComponent(TransformComponent const& source) = default;
    TransformComponent(TransformComponent&& source) = default;
    
};

#endif /* TransformComponent_hpp */
