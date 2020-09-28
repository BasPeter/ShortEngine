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
#include <SDL2_image/SDL_image.h>
#include <set>
#include <map>

#include "Game.hpp"
#include "AssetManager.hpp"
#include "SpriteSheet.hpp"

class SpriteComponent
{
public:
    const char* name{""};
    SpriteSheet* sprite_sheet;
        
//    SpriteComponent(const char* n, unsigned int f, unsigned int s_w, unsigned int s_h, unsigned int f_w, unsigned int f_h)
    SpriteComponent(unsigned int f_w, unsigned int f_h, std::vector<SpriteSheet*> sheets)
    {
//        sprite_sheets = sheets;
    }
    
    ~SpriteComponent()
    {
        std::cout << "Sprite Component Destructor Called" << std::endl;
    }
    
    void draw(float position[2], float scale[2], SDL_Rect frame)
    {
        
    }
    
private:
};

#endif /* SpriteComponent_hpp */
