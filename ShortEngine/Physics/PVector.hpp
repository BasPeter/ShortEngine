//
//  PVector.hpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 29/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef PVector_hpp
#define PVector_hpp

#include <stdio.h>
#include <iostream>

class PVector
{
public:
    
    PVector(float x, float y);
    
    PVector& operator=(const PVector&);
    PVector& operator+=(const PVector&);
    PVector& operator/=(const float&);
    PVector& operator*=(const float&);
    PVector& operator*=(const float&&);
    
    PVector operator+(const PVector&);
    PVector& operator*(const float&);
    PVector operator/(const float&);
    
    float GetX() const { return _x; };
    float GetY() const { return _y; };
    
private:
    float _x;
    float _y;
};

#endif /* PVector_hpp */
