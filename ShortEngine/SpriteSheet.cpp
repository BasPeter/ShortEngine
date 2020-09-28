//
//  SpriteSheet.cpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 27/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#include "SpriteSheet.hpp"

SpriteSheet::SpriteSheet(std::string sheet_name, int frames, int sheet_width, int sheet_height, int columns, int rows)
{
    texture = Game::Assets->GetTexture(sheet_name);
        
    sheet_size[0] = sheet_width;
    sheet_size[1] = sheet_height;
    
    _frames = frames;
    _columns = columns;
    _rows = rows;
}

SDL_Rect GetFrame(int frame)
{
    return SDL_Rect{0,0,0,0};
}
