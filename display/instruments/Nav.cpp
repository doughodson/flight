
#include "Nav.hpp"

#include <iostream>
#include <string>

#include "SDL2/SDL_image.h"
#include "../Display.hpp"
#include "../sdl_utils.hpp"

Nav::Nav(const int xpos, const int ypos): xpos(xpos), ypos(ypos)
{
   // load all textures associated with alt
   tex_face = sdl_utils::load_texture("../assets/images/instruments/hsi/hsi_face.svg");
   tex_case = sdl_utils::load_texture("../assets/images/instruments/hsi/hsi_case.svg");

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

Nav::~Nav()
{
   SDL_DestroyTexture(tex_face);
   SDL_DestroyTexture(tex_case);
}

void Nav::update(const float dt)
{
   heading += 0.2;
}

void Nav::render()
{
   SDL_RenderCopyEx(Display::renderer, tex_face, &src_rect, &dest_rect, -heading, 0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, tex_case, &src_rect, &dest_rect,        0, 0, SDL_FLIP_NONE);
}


