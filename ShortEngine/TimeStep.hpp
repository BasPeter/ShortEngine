//
//  TimeStep.hpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 29/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef TimeStep_hpp
#define TimeStep_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class TimeStep
{
public:
    
    TimeStep();
    ~TimeStep();
    static TimeStep* Create();
    
    void Reset();
    Uint32& get() { return _timestep; };
    
private:
    static TimeStep* _timestep_ptr;
    float _start_frame{0};
    Uint32 _timestep{0};
};

#endif /* TimeStep_hpp */
