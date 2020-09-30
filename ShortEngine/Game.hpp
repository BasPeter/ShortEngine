//
//  Game.hpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 24/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>
#include <iostream>
#include <vector>

#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "AssetManager.hpp"
#include "SpriteSheetManager.hpp"
#include "TimeStep.hpp"
#include "Components.hpp"

class AssetManager;
class SpriteSheetManager;
class EntityManager;

class Game
{ 
public:
    
    Game();
    ~Game();
    
    void init(const std::string title, int width, int height, bool fullscreen);
    
    void Update();
    void HandleEvents();
    bool isRunning() const { return _running; };
    void Render();
    void Clean();
    
    void UpdateWindowTitle(std::string title, int fps);

    static SDL_Renderer *Renderer;
    static SDL_Event *Events;
    static EntityManager *Registry;
    static AssetManager *Assets;
    static SpriteSheetManager *SpriteSheets;
    static TimeStep *TimeStep;
    
private:
    bool _running;
    
    SDL_Window* _window;
};

#endif /* Game_hpp */
