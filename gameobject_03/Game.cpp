
#include "Game.hpp"

#include <iostream>
#include <string>

#include "SDL2/SDL_image.h"

#define SOL_ALL_SAFETIES_ON 1
#include "sol/sol.hpp"

#include "sdl_utils.hpp"
#include "gameobjects/Chopper.hpp"
#include "gameobjects/Tank.hpp"
#include "gameobjects/Pacman.hpp"

SDL_Renderer* Game::renderer{};
SDL_Window* Game::window{};
sol::state Game::lua;

Game::Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
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
      lua.open_libraries(sol::lib::base, sol::lib::package);
      std::cout << "Lua libraries opened..." << std::endl;
      try {
         lua.script_file("config.lua");
      } catch (sol::error& e) {
         std::cout << "Lua script error!" << std::endl;
         std::cout << e.what() << std::endl;
         return;
      }
      std::cout << "Lua configuration file loaded..." << std::endl;
      is_running = true;
   } else {
      is_running = false;
   }
}

Game::~Game()
{
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();
}

void Game::load_level()
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

   sol::table gameobjs = lua["gameobjs"];
   for (const auto& key_value_pair : gameobjs) {
      sol::object key = key_value_pair.first;
      sol::object value = key_value_pair.second;
      sol::table tbl{static_cast<sol::table>(value)};
      std::string kind{tbl["kind"]};
      std::cout << "Creating : " << key.as<std::string>() << " kind : " << kind << std::endl;
      if (kind == "chopper") {
         auto chopper = std::make_unique<Chopper>(static_cast<float>(tbl["xpos"]),
                                                  static_cast<float>(tbl["ypos"]),
                                                  static_cast<float>(tbl["xvel"]),
                                                  static_cast<float>(tbl["yvel"]));
         game_objs.emplace_back(std::move(chopper));
      } else if (kind == "tank") {
         auto tank = std::make_unique<Tank>(static_cast<float>(tbl["xpos"]),
                                            static_cast<float>(tbl["ypos"]),
                                            static_cast<float>(tbl["xvel"]),
                                            static_cast<float>(tbl["yvel"]));
         game_objs.emplace_back(std::move(tank));
      } else if (kind == "pacman") {
         auto pacman  = std::make_unique<Pacman>(static_cast<float>(tbl["xpos"]),
                                                 static_cast<float>(tbl["ypos"]),
                                                 static_cast<float>(tbl["xvel"]),
                                                 static_cast<float>(tbl["yvel"]));
         game_objs.emplace_back(std::move(pacman));
      }
   }
}

void Game::handle_events()
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

void Game::update(const float dt)
{
   for (auto& i: game_objs) {
      i->update(dt);
   }
}

void Game::render()
{
   SDL_RenderClear(renderer);
   for (auto& i: game_objs) {
      i->render();
   }
   SDL_RenderPresent(renderer);
}

