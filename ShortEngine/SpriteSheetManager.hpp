//
//  SpriteSheetManager.hpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 27/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef SpriteSheetManager_hpp
#define SpriteSheetManager_hpp

#include <stdio.h>
#include <string>
#include <map>
#include <array>

#include "Game.hpp"
#include "SpriteSheet.hpp"

class SpriteSheet;

class SpriteSheetManager
{
public:
    SpriteSheetManager(){};
    
    static SpriteSheetManager* Create();
    static void DeleteSpriteSheet();
    
    void RegisterSpriteSheet(std::string name, std::string sheet_name, std::string path, int frames, int sheet_width, int sheet_height, int columns, int rows);
    
    template <typename... Args>
    std::vector<SpriteSheet*> GetSpriteSheets(Args... args);
    
private:
    static SpriteSheetManager* _manager;
    
    std::map<std::string, SpriteSheet*> _sprite_sheets;
};

#endif /* SpriteSheetManager_hpp */
