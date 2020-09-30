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
#include <vector>

#include "AssetManager.hpp"
#include "SpriteSheet.hpp"

class SpriteSheet;

class SpriteComponent
{
public:
    const char* name{""};
    SpriteSheet* sprite_sheet;
    int current_frame{0};
    
    SpriteComponent(SpriteSheet* sprite_sheet, int current_frame): sprite_sheet(sprite_sheet), current_frame(current_frame)
    {
    }
    
    ~SpriteComponent()
    {
        std::cout << "Sprite Component Destructor Called" << std::endl;
    }
    
    void Draw(SDL_Renderer* renderer, PVector& position, float scale[2])
    {
        SDL_Rect source = sprite_sheet->GetFrame(current_frame);
        SDL_Rect destination = GetDestinationRect(source, position, scale);
        SDL_RenderCopy(renderer, sprite_sheet->texture, &source, &destination);
    }
    
private:
    SDL_Rect GetDestinationRect(SDL_Rect& rect, PVector& position, float scale[2]) {

        //Transform source rect using given position and scale
        SDL_Rect result{(int)position.GetX(), (int)position.GetY(), rect.w, rect.h};
        result.w *= scale[0];
        result.h *= scale[1];
        return result;
    }
};

#endif /* SpriteComponent_hpp */
