
#include "Adi.hpp"

#include <iostream>
#include <string>

#include "SDL2/SDL_image.h"

#include "sdl_utils.hpp"

SDL_Renderer* Adi::renderer{};
SDL_Window* Adi::window{};

Adi::Adi(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
   Uint32 flags{};
   if (fullscreen) {
      flags = SDL_WINDOW_FULLSCREEN;
   }

   if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
      std::cout << "Subsystems initialized..." << std::endl;
      window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
      if (window) {
         std::cout << "Window created..." << std::endl;
      }
      renderer = SDL_CreateRenderer(window, -1, 0);
      if (renderer) {
         SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
         std::cout << "Renderer created..." << std::endl;
      }
      is_running = true;
   } else {
      is_running = false;
   }
}

Adi::~Adi()
{
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();
}

void Adi::load_level()
{
/*
   sol::table chopper_tbl = lua["gameobjs"]["chopper"];
   sol::table tank_tbl    = lua["gameobjs"]["tank"];
   sol::table pacman_tbl  = lua["gameobjs"]["pacman"];

   auto chopper = std::make_unique<Chopper>(static_cast<float>(chopper_tbl["xpos"]),
                                            static_cast<float>(chopper_tbl["ypos"]),
                                            static_cast<float>(chopper_tbl["xvel"]),
                                            static_cast<float>(chopper_tbl["yvel"]));
   auto tank    = std::make_unique<Tank>(   static_cast<float>(tank_tbl["xpos"]),
                                            static_cast<float>(tank_tbl["ypos"]),
                                            static_cast<float>(tank_tbl["xvel"]),
                                            static_cast<float>(tank_tbl["yvel"]));
   auto pacman  = std::make_unique<Pacman>( static_cast<float>(pacman_tbl["xpos"]),
                                            static_cast<float>(pacman_tbl["ypos"]),
                                            static_cast<float>(pacman_tbl["xvel"]),
                                            static_cast<float>(pacman_tbl["yvel"]));
   game_objs.emplace_back(std::move(chopper));
   game_objs.emplace_back(std::move(tank));
   game_objs.emplace_back(std::move(pacman));
*/
}

void Adi::handle_events()
{
   SDL_Event event;
   SDL_PollEvent(&event);
   switch (event.type) {
      case SDL_QUIT:
         is_running = false;
         break;
      default:
         break;
   }
}

void Adi::update(const float dt)
{
//   for (auto& i: game_objs) {
//      i->update(dt);
//   }
}

void Adi::render()
{
   SDL_RenderClear(renderer);
//   for (auto& i: game_objs) {
//      i->render();
//   }
   SDL_RenderPresent(renderer);
}


