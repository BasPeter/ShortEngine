//
//  SpriteSheet.hpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 27/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef SpriteSheet_hpp
#define SpriteSheet_hpp

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class SpriteSheet
{
public:
    SDL_Texture* texture;
    int sheet_size[2];
        
    SpriteSheet(SDL_Texture* texture, int frames, int sheet_width, int sheet_height, int columns, int rows);
    
    SDL_Rect GetFrame(int frame);
    int GetFrames() { return _frames; };
        
private:
    int _frames;
    int _columns;
    int _rows;
};

#endif /* SpriteSheet_hpp */
