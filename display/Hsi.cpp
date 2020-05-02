
#include "Hsi.hpp"

#include <iostream>
#include <string>

#include "SDL2/SDL_image.h"
#include "Display.hpp"
#include "sdl_utils.hpp"

Hsi::Hsi(const int xpos, const int ypos): xpos(xpos), ypos(ypos)
{
   // load all textures associated with alt
   texFace = sdl_utils::load_texture("../assets/images/instruments/hsi/hsi_face.svg");
   texCase = sdl_utils::load_texture("../assets/images/instruments/hsi/hsi_case.svg");

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

Hsi::~Hsi()
{
   SDL_DestroyTexture(texFace);
   SDL_DestroyTexture(texCase);
}

void Hsi::update(const float dt)
{
   heading += 0.2;
}

void Hsi::render()
{
   SDL_RenderCopyEx(Display::renderer, texFace, &src_rect, &dest_rect, -heading, 0, SDL_FLIP_NONE);
   SDL_RenderCopy(Display::renderer, texCase, &src_rect, &dest_rect);
}


