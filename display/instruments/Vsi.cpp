
#include "Vsi.hpp"

#include <iostream>
#include <string>

#include "SDL2/SDL_image.h"
#include "../Display.hpp"
#include "../sdl_utils.hpp"

Vsi::Vsi(const int xpos, const int ypos): xpos(xpos), ypos(ypos)
{
   // load all textures associated with alt
   tex_face = sdl_utils::load_texture("../assets/images/instruments/vsi/vsi_face.svg");
   tex_hand = sdl_utils::load_texture("../assets/images/instruments/vsi/vsi_hand.svg");
   tex_case = sdl_utils::load_texture("../assets/images/instruments/vsi/vsi_case.svg");

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

Vsi::~Vsi()
{
   SDL_DestroyTexture(tex_face);
   SDL_DestroyTexture(tex_hand);
   SDL_DestroyTexture(tex_case);
}

void Vsi::update(const float dt)
{
   climb_rate += 1.0;
}

void Vsi::render()
{
   SDL_RenderCopyEx(Display::renderer, tex_face, &src_rect, &dest_rect, 0, 0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, tex_hand, &src_rect, &dest_rect, climb_rate*0.086f, 0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, tex_case, &src_rect, &dest_rect, 0, 0, SDL_FLIP_NONE);
}


