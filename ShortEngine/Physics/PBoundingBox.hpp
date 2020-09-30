//
//  PBoundingBox.hpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 30/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef PBoundingBox_hpp
#define PBoundingBox_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <list>
#include <vector>

#include "PVector.hpp"

class PBoundingBox
{
public:
    PBoundingBox(int x, int y, int w, int h);
    
    std::vector<PVector> doesCollide();
    PVector getContraintFunction();
    
    void UpdatePosition(PVector position);
    SDL_Rect* GetBoundingBox() { return &_bounding_box; };
    
    static void sort_bounding_boxes();
    
private:
    
    PVector _offset_position{0,0};
    SDL_Rect _bounding_box{0,0,0,0};
    
    static bool compare_x_pos(const PBoundingBox* lhs, const PBoundingBox* rhs);
    static std::list<PBoundingBox*> _bounding_boxes;
};

#endif /* PBoundingBox_hpp */
