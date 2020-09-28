//
//  SpriteSheetManager.cpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 27/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#include "SpriteSheetManager.hpp"

SpriteSheetManager* SpriteSheetManager::_manager = nullptr;

SpriteSheetManager* SpriteSheetManager::Create()
{
    _manager = new SpriteSheetManager();
    return _manager;
}

void SpriteSheetManager::DeleteSpriteSheet() {
    delete _manager;
}

void SpriteSheetManager::RegisterSpriteSheet(std::string name, std::string sheet_name, std::string path, int frames, int sheet_width, int sheet_height, int columns, int rows) {
    // Register texture on AssetManager;
    Game::Assets->RegisterTexture(sheet_name, path.c_str());
    
    // Add SpriteSheet to map with corresponding key
    SpriteSheet* sprite_sheet_ptr = new SpriteSheet(sheet_name, frames, sheet_width, sheet_height, columns, rows);
    _sprite_sheets.emplace(name, sprite_sheet_ptr);
}

template <typename... Args>
std::vector<SpriteSheet*> SpriteSheetManager::GetSpriteSheets(Args... args)
{
    std::array<const char*, sizeof...(args)> sheet_names = {args...};
    std::vector<SpriteSheet*> result;
    
    // iterate over arguments, add sprite sheet to result if found.
    for (auto sheet_name : sheet_names)
    {
        auto search = _sprite_sheets.find(std::string(sheet_name));
        if (search != _sprite_sheets.end())
        {
            result.emplace_back(_sprite_sheets[search->first]);
        }
    }
    return result;
}

template std::vector<SpriteSheet*> SpriteSheetManager::GetSpriteSheets(const char*);
template std::vector<SpriteSheet*> SpriteSheetManager::GetSpriteSheets(const char*, const char*);
 

