
#include "Display.hpp"

#include <iostream>
#include <string>

#include "SDL2/SDL_image.h"
#include "sdl_utils.hpp"

#include "Adi.hpp"
#include "Alt.hpp"
#include "Asi.hpp"

SDL_Renderer* Display::renderer{};
SDL_Window* Display::window{};

Display::Display(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
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

Display::~Display()
{
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();
}

void Display::load_level()
{
   adi = std::make_unique<Adi>(0, 0);
   alt = std::make_unique<Alt>(241, 0);
   asi = std::make_unique<Asi>(482, 0);
}

void Display::handle_events()
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

void Display::update(const float dt)
{
   adi->update(dt);
   alt->update(dt);
   asi->update(dt);
}

void Display::render()
{
   SDL_RenderClear(Display::renderer);
   adi->render();
   alt->render();
   asi->render();
   SDL_RenderPresent(Display::renderer);
}


