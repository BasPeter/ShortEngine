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
#include <vector>

#include "PBoundingBox.hpp"
#include "PVector.hpp"

#define MAX_ITERATIONS 15

class CollisionComponent
{
public:
    
    CollisionComponent(int x, int y, int w, int h, bool show_bounding_box): bounding_box(x, y, w, h), _show_bounding_box(show_bounding_box)
    {
    }
    
    PVector resolve(const PVector& velocity, const PVector& acceleration, const float& mass, Uint32& timestep)
    {
        
        // 1. Integrate applied forces using semi-implicit Euler as in Part I, yielding tentative velocities. These velocities may violate the constraints and need to be corrected before being applied.
        bounding_box.Move(velocity.GetX() + acceleration.GetX(), velocity.GetY() + acceleration.GetY());

        PVector constraint_impulse{0,0};
        PVector constraint_impulse_step{0,0};
        std::vector<PVector> constraint_functions = bounding_box.getContraintFunction();
        int iteration = 0;
        
        
        // 2. Apply impulses sequentially for all constraints, to correct the velocity errors. Repeat for several iterations, until impulses become small or after a maximum number of iterations is reached.
        while (constraint_functions.size() > 0 && iteration < MAX_ITERATIONS)
        {
            
            for (PVector constraint : constraint_functions)
            {
                constraint_impulse_step += (constraint);
            }

            // calculate correction on location
            PVector correction{
                (constraint_impulse_step.GetX() / mass),
                (constraint_impulse_step.GetY() / mass)
            };

            // 3. Use the new velocities to simulate motion, updating positions, again using semi-implicit Euler.
            bounding_box.Move(std::move((correction) / (timestep/10.0f)));
            
            constraint_impulse += constraint_impulse_step;
            constraint_functions = bounding_box.getContraintFunction();
            iteration++;
        }
        
        return constraint_impulse;
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

