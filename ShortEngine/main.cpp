//
//  main.cpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 24/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#include <iostream>
#include "Game.hpp"

constexpr int kFramesPerSecond{60};
constexpr int kMsPerFrame{1000/kFramesPerSecond};

int main(int argc, const char * argv[]) {

    Game game;
    game.init("Test", 600, 480, false);
    
    unsigned lastWindowTitleUpdate{0};
    int count{0};
    
    while(game.isRunning())
    {
        int frameStart = SDL_GetTicks();
        
        // Core Game loop
        game.HandleEvents();
        game.Update();
        game.Render();
        
        
        int frameEnd = SDL_GetTicks();
        int duration = frameEnd - frameStart;
        
        //Time control
        if (duration < kMsPerFrame)
        {
            SDL_Delay(kMsPerFrame - duration);
        }
        
        if (frameEnd - 1000 > lastWindowTitleUpdate)
        {
            game.UpdateWindowTitle("Test", count);
            count = 0;
            lastWindowTitleUpdate = frameEnd;
        }
        count++;
    };
    
    game.Clean();

    return 0;
}
