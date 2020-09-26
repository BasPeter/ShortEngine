//
//  AssetManager.cpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 26/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#include "AssetManager.hpp"

AssetManager* AssetManager::_manager = nullptr;

AssetManager* AssetManager::Create()
{
    _manager = new AssetManager();
    return _manager;
}

void AssetManager::Destroy()
{
    delete _manager;
}

void AssetManager::RegisterTexture(std::string name, const char *path)
{
    // Create texture from surface
    SDL_Surface* tempSurface = IMG_Load(path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::Renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    
    _textures.emplace(name, texture);
}

SDL_Texture* AssetManager::GetTexture(std::string name)
{
    return _textures[name];
}
