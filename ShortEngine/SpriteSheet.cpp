//
//  SpriteSheet.cpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 27/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#include "SpriteSheet.hpp"

SpriteSheet::SpriteSheet(SDL_Texture* texture, int frames, int sheet_width, int sheet_height, int columns, int rows)
{
    this->texture = texture;
        
    sheet_size[0] = sheet_width;
    sheet_size[1] = sheet_height;
    
    _frames = frames;
    _columns = columns;
    _rows = rows;
}

SDL_Rect SpriteSheet::GetFrame(int frame)
{
    // Find SDL_Rect defining given frame
    return SDL_Rect{
        (frame % _rows) * (sheet_size[0] / _rows),
        (frame % _columns) * (sheet_size[1] / _columns),
        sheet_size[0]/_rows,
        sheet_size[1]/_columns};
}
