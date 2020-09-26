//
//  AnimateComponent.hpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 26/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef AnimateComponent_hpp
#define AnimateComponent_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

struct AnimateComponent
{
    unsigned int current_frame{0};
    unsigned int speed{0};
    Uint32 last_frame{0};
    bool animate{false};
    
    AnimateComponent(int c_f, int s, bool a)
    {
        current_frame = c_f;
        speed = s;
        animate = a;
    }
    
    AnimateComponent(AnimateComponent const& source) = default;
    AnimateComponent(AnimateComponent&& source) = default;
};

#endif /* AnimateComponent_hpp */
