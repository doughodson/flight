
#include "Adi.hpp"

#include <iostream>
#include <string>

#include "SDL2/SDL_image.h"
#include "Display.hpp"
#include "sdl_utils.hpp"

Adi::Adi(const int xpos, const int ypos): xpos(xpos), ypos(ypos)
{
   // load all textures associated with adi
   texBack = sdl_utils::load_texture("../assets/images/instruments/adi/adi_back_240x240.png");
   texFace = sdl_utils::load_texture("../assets/images/instruments/adi/adi_face_240x240.png");
   texRing = sdl_utils::load_texture("../assets/images/instruments/adi/adi_ring_240x240.png");
   texCase = sdl_utils::load_texture("../assets/images/instruments/adi/adi_case_240x240.png");

   // initialize source and destination rects
   src_rect.x = 0;
   src_rect.y = 0;
   src_rect.h = 240;
   src_rect.w = 240;

   dest_rect.x = xpos + src_rect.w;
   dest_rect.y = ypos + src_rect.h;
   dest_rect.w = 240;
   dest_rect.h = 240;
}

Adi::~Adi()
{
   SDL_DestroyTexture(texBack);
   SDL_DestroyTexture(texFace);
   SDL_DestroyTexture(texRing);
   SDL_DestroyTexture(texCase);
}

void Adi::update(const float dt)
{
   angle += .05;
}

void Adi::render()
{
   SDL_RenderClear(Display::renderer);
   SDL_RenderCopyEx(Display::renderer, texBack, &src_rect, &dest_rect, angle, 0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, texFace, &src_rect, &dest_rect, angle, 0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, texRing, &src_rect, &dest_rect, angle, 0, SDL_FLIP_NONE);
   SDL_RenderCopy(Display::renderer, texCase, &src_rect, &dest_rect);
   SDL_RenderPresent(Display::renderer);
}


