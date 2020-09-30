//
//  CollisionComponent.hpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 29/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef CollisionComponent_hpp
#define CollisionComponent_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

#include "PBoundingBox.hpp"

class CollisionComponent
{
public:
    
    CollisionComponent(int x, int y, int w, int h, bool show_bounding_box): bounding_box(x, y, w, h), _show_bounding_box(show_bounding_box)
    {
//        _components.emplace_back(*this);
    }
    
    void resolve()
    {
        /*
        1. Integrate applied forces using semi-implicit Euler as in Part I, yielding tentative velocities. These velocities may violate the constraints and need to be corrected before being applied.

        2. Apply impulses sequentially for all constraints, to correct the velocity errors. Repeat for several iterations, until impulses become small or after a maximum number of iterations is reached.

        3. Use the new velocities to simulate motion, updating positions, again using semi-implicit Euler.
        */
        
//        std::vector<PVector> impulses = bounding_box.doesCollide();
//        for (PVector impulse : impulses)
//        {
//            physics->applyForce(impulse);
//        }
        
        
    }
    
    void draw(SDL_Renderer* renderer)
    {
        if (_show_bounding_box)
        {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderDrawRect(renderer, bounding_box.GetBoundingBox());
        }
    }
    
    PBoundingBox bounding_box;

private:
    bool _show_bounding_box;
    bool _collides{false};
};

#endif /* CollisionComponent_hpp */

