
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
   // load all textures associated with adi
   texBack = sdl_utils::load_texture("../assets/images/instruments/adi/adi_back_240x240.png");
   texFace = sdl_utils::load_texture("../assets/images/instruments/adi/adi_face_240x240.png");
   texRing = sdl_utils::load_texture("../assets/images/instruments/adi/adi_ring_240x240.png");
   texCase = sdl_utils::load_texture("../assets/images/instruments/adi/adi_case_240x240.png");
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
   src_rect.x = 0;
   src_rect.y = 0;
   src_rect.h = 240;
   src_rect.w = 240;

   dest_rect.x = 0;
   dest_rect.y = 0;
   dest_rect.w = 240;
   dest_rect.h = 240;

   angle += .05;
}

void Adi::render()
{
   SDL_RenderClear(renderer);
   SDL_RenderCopyEx(Adi::renderer, texBack, &src_rect, &dest_rect, angle, 0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Adi::renderer, texFace, &src_rect, &dest_rect, angle, 0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Adi::renderer, texRing, &src_rect, &dest_rect, angle, 0, SDL_FLIP_NONE);
   SDL_RenderCopy(Adi::renderer, texCase, &src_rect, &dest_rect);
   SDL_RenderPresent(renderer);
}


