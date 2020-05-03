
#include "Asi.hpp"

#include <iostream>
#include <string>

#include "SDL2/SDL_image.h"
#include "../Display.hpp"
#include "../sdl_utils.hpp"

Asi::Asi(const int xpos, const int ypos): xpos(xpos), ypos(ypos)
{
   // load all textures associated with alt
   texFace = sdl_utils::load_texture("../assets/images/instruments/asi/asi_face.svg");
   texHand = sdl_utils::load_texture("../assets/images/instruments/asi/asi_hand.svg");
   texCase = sdl_utils::load_texture("../assets/images/instruments/asi/asi_case.svg");

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

Asi::~Asi()
{
   SDL_DestroyTexture(texFace);
   SDL_DestroyTexture(texHand);
   SDL_DestroyTexture(texCase);
}

void Asi::update(const float dt)
{
   angle += .2;
}

void Asi::render()
{
   SDL_RenderCopy(Display::renderer, texFace, &src_rect, &dest_rect);
   //SDL_RenderCopy(Display::renderer, texHand, &src_rect, &dest_rect);
   SDL_RenderCopyEx(Display::renderer, texHand, &src_rect, &dest_rect, angle, 0, SDL_FLIP_NONE);
   SDL_RenderCopy(Display::renderer, texCase, &src_rect, &dest_rect);
}


