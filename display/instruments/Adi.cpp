
#include "Adi.hpp"

#include <iostream>
#include <string>

#include "SDL2/SDL_image.h"
#include "../Display.hpp"
#include "../sdl_utils.hpp"

Adi::Adi(const int xpos, const int ypos): xpos(xpos), ypos(ypos)
{
   // load all textures associated with adi
   tex_back = sdl_utils::load_texture("../assets/images/instruments/adi/adi_back.svg");
   tex_face = sdl_utils::load_texture("../assets/images/instruments/adi/adi_face.svg");
   tex_ring = sdl_utils::load_texture("../assets/images/instruments/adi/adi_ring.svg");
   tex_case = sdl_utils::load_texture("../assets/images/instruments/adi/adi_case.svg");

   // initialize source and destination rects
   src_rect.x = 0;
   src_rect.y = 0;
   src_rect.h = 240;
   src_rect.w = 240;

   dest_rect.x = xpos;
   dest_rect.y = ypos;
   dest_rect.w = 240;
   dest_rect.h = 240;
}

Adi::~Adi()
{
   SDL_DestroyTexture(tex_back);
   SDL_DestroyTexture(tex_face);
   SDL_DestroyTexture(tex_ring);
   SDL_DestroyTexture(tex_case);
}

void Adi::update(const float dt)
{
   angle += .05;
}

void Adi::render()
{
   SDL_RenderCopyEx(Display::renderer, tex_back, &src_rect, &dest_rect, angle, 0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, tex_face, &src_rect, &dest_rect, angle, 0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, tex_ring, &src_rect, &dest_rect, angle, 0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, tex_case, &src_rect, &dest_rect, 0,     0, SDL_FLIP_NONE);
}


