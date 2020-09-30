//
//  PBoundingBox.cpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 30/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#include "PBoundingBox.hpp"

std::list<PBoundingBox*> PBoundingBox::_bounding_boxes = {};

PBoundingBox::PBoundingBox(int dx, int dy, int w, int h): _offset_position(dx, dy)
{
    _bounding_box = SDL_Rect{dx,dy,w,h};
    _bounding_boxes.emplace_back(this);
}

bool PBoundingBox::compare_x_pos(const PBoundingBox* lhs, const PBoundingBox* rhs)
{
    return lhs->_bounding_box.x < rhs->_bounding_box.x;
}

void PBoundingBox::UpdatePosition(PVector position)
{
    _bounding_box.x = position.GetX() + _offset_position.GetX();
    _bounding_box.y = position.GetY() + _offset_position.GetY();
    
    sort_bounding_boxes();
}

void PBoundingBox::sort_bounding_boxes()
{
    _bounding_boxes.sort(compare_x_pos);
}

std::vector<PVector> PBoundingBox::doesCollide()
{
    std::vector<PVector> constraint_impulse{};
    for (PBoundingBox* other : _bounding_boxes)
    {
        if (this != other)
        {
//            // Everything else is not worth checking
//            // AABB horizontal check
            if (
                (other->_bounding_box.x + other->_bounding_box.w > this->_bounding_box.x)
                ||
                this->_bounding_box.x + this->_bounding_box.w > other->_bounding_box.x)
                {
                    SDL_Rect intersect_rect;
                    auto intersect = SDL_IntersectRect(&(other->_bounding_box), &(this->_bounding_box), &intersect_rect);
                    
                    if (intersect != SDL_FALSE)
                    {
                        if (intersect_rect.w > intersect_rect.h)
                        {
                            constraint_impulse.emplace_back(0, -intersect_rect.h);
                        } else {
                            constraint_impulse.emplace_back(intersect_rect.x, 0);
                        }
                    }
                }
        }
    }
    return constraint_impulse;
}

