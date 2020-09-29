//
//  PVector.cpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 29/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#include "PVector.hpp"

PVector::PVector(float x, float y): _x(x), _y(y)
{
    
}

PVector& PVector::operator=(const PVector& other)
{
    this->_x = other.GetX();
    this->_y = other.GetY();
    return *this;
}

PVector& PVector::operator+=(const PVector& other)
{
    this->_x += other.GetX();
    this->_y += other.GetY();
    return *this;
}

PVector& PVector::operator/=(const float& n)
{
    this->_x /= n;
    this->_y /= n;
    return *this;
}

PVector& PVector::operator*=(const float& n)
{
    this->_x *= n;
    this->_y *= n;
    return *this;
}

PVector& PVector::operator*=(const float&& n)
{
    this->_x *= n;
    this->_y *= n;
    return *this;
}

