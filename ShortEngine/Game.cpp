//
//  Game.cpp
//  ShortEngine
//
//  Created by Bas Peter Dijkema on 24/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#include "Game.hpp"

SDL_Renderer *Game::Renderer = NULL;
SDL_Event *Game::Events;
EntityManager *Game::Registry = nullptr;
AssetManager *Game::Assets = nullptr;

Game::Game()
{
    
}

Game::~Game()
{
    
}

void Game::init(const std::string title, int width, int height, bool fullscreen)
{
    int flags = 0;
    
    if (fullscreen) { flags = SDL_WINDOW_FULLSCREEN; }
    //Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize.." << std::endl;
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
    }
    
    _window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    
    if (nullptr == _window) {
        std::cout << "Window could not be created.." << std::endl;
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
    }
    
    // Create Renderer
    Renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
      
      if (nullptr == Renderer) {
          std::cout << "Renderer could not be created.." << std::endl;
          std::cout << "SDL Error: " << SDL_GetError() << std::endl;
      }
    
    // Create AssetManager
    Assets = AssetManager::Create();
    Assets->RegisterTexture("character_run", "Assets/Character_Run.png");
    Assets->RegisterTexture("character_attack", "Assets/Character_Attack.png");

    
    // Init PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    }
    
    Registry = EntityManager::CreateRegistry();
    
    Entity* E1 = Registry->Create();
    Entity* E2 = Registry->Create();
            
    Registry->Emplace<SpriteComponent>(E1, "character_run", 6, 137, 264, 137, 44);
    Registry->Emplace<TransformComponent>(E1, 100.0f, 100.0f, 2.0f, 2.0f, 0.0f);
    Registry->Emplace<AnimateComponent>(E1, 0, 1000/6, true);
    
    Registry->Emplace<SpriteComponent>(E2, "character_attack", 13, 137, 572, 137, 44);
    Registry->Emplace<TransformComponent>(E2, 300.0f, 100.0f, 2.0f, 2.0f, 0.0f);
    Registry->Emplace<AnimateComponent>(E2, 0, 1000/12, true);

    _running = true;
}

void Game::UpdateWindowTitle(std::string gameTitle, int fps) {
    std::string title {gameTitle + " | FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(_window, title.c_str());
}

void Game::Render()
{
    SDL_SetRenderDrawColor(Renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(Renderer);
    
    SDL_SetRenderDrawColor(Renderer, 0xFF, 0xCC, 0x00, 0xFF);
        
//    SDL_RenderCopy(Renderer, Assets->GetTexture("character_run"), NULL, NULL);
    
    auto manager = dynamic_cast<ComponentManager<SpriteComponent>*>(Registry->GetComponentManager<SpriteComponent>());
    
    SDL_Rect sheet;
    auto group = manager->Group<TransformComponent>();
    for (auto& [sprite, transform] : group) {
        sheet.x = transform->position[0];
        sheet.y = transform->position[1];
        sheet.w = sprite->frame.w * transform->scale[0];
        sheet.h = sprite->frame.h * transform->scale[1];

        SDL_RenderCopy(Renderer, Assets->GetTexture(sprite->name), &(sprite->frame), &sheet);
    }
    SDL_RenderPresent(Renderer);
}

void Game::Update()
{
    auto manager = dynamic_cast<ComponentManager<SpriteComponent>*>(Registry->GetComponentManager<SpriteComponent>());
    auto group = manager->Group<AnimateComponent>();
    
    for (auto& [sprite, animate] : group)
    {
        if (animate->animate && SDL_GetTicks() - animate->last_frame > animate->speed)
        {
            sprite->frame.y += sprite->frame.h;
            animate->current_frame += 1;
            if (animate->current_frame >= sprite->frames) {
                animate->current_frame = 0;
                sprite->frame.y = 0;
            }
            animate->last_frame = SDL_GetTicks();
        };
    }
}

void Game::Clean()
{
    EntityManager::DestroyRegistry();
    
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Game::HandleEvents()
{
    SDL_Event e;
    
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            _running = false;
        }
    }
}
