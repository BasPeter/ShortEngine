//
//  TimeStep.cpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 29/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#include "TimeStep.hpp"

TimeStep* TimeStep::_timestep_ptr = nullptr;

TimeStep::TimeStep()
{
    _start_frame = SDL_GetTicks();
}

TimeStep::~TimeStep()
{
    delete _timestep_ptr;
}

TimeStep* TimeStep::Create()
{
    _timestep_ptr = new TimeStep();
    return _timestep_ptr;
}

void TimeStep::Reset() {
    _timestep = SDL_GetTicks() - _start_frame;
    _start_frame = SDL_GetTicks();
}
