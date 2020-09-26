//
//  AssetManager.hpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 26/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef AssetManager_hpp
#define AssetManager_hpp

#include <stdio.h>
#include <SDL2_image/SDL_image.h>
#include <string>
#include <map>

#include "Game.hpp"

class AssetManager
{
public:
    static AssetManager* Create();
    static void Destroy();
    
    void RegisterTexture(std::string name, const char* path);
    SDL_Texture* GetTexture(std::string name);
    
private:
    static AssetManager* _manager;
    
    std::map<std::string, SDL_Texture*> _textures;
};

#endif /* AssetManager_hpp */
