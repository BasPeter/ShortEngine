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
    
    Registry = EntityManager::CreateRegistry();
    
        
    for (float i = 1; i <= 300; i++)
        for (float ii = 1; ii <= 200; ii++) {
            {
                Registry->Emplace<TransformComponent>(Registry->Create(), 5.0f * i, 5.0f * ii, 2.0f, 2.0f, 0.0f);
            }
    }
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

    auto manager = dynamic_cast<ComponentManager<TransformComponent>*>(Registry->GetComponentManager<TransformComponent>());
    auto& view = manager->GetView();
    
    for (auto& component : view)
    {
        SDL_RenderDrawPoint(Renderer, component.position[0], component.position[1]);
    }
    SDL_RenderPresent(Renderer);
}

void Game::Update()
{
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
