//
//  SpriteComponent.hpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 26/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include <SDL2/SDL.h>

struct SpriteComponent
{
    const char* name{""};
    unsigned int frames{0};
    
    unsigned int sheet_size[2];
    unsigned int frame_size[2];
    
    SDL_Rect frame;

    
    SpriteComponent(const char* n, unsigned int f, unsigned int s_w, unsigned int s_h, unsigned int f_w, unsigned int f_h)
    {
        name = n;
        frames = f;
        
        sheet_size[0] = s_w;
        sheet_size[1] = s_h;
        
        frame.x = 0;
        frame.y = 0;
        frame.w = f_w;
        frame.h = f_h;
        
        frame_size[0] = f_w;
        frame_size[1] = f_h;
    }
    
    ~SpriteComponent()
    {
        std::cout << "Sprite Component Destructor Called" << std::endl;
    }
    
    SpriteComponent(SpriteComponent const& source) = default;
    SpriteComponent(SpriteComponent&& source) = default;
};

#endif /* SpriteComponent_hpp */
