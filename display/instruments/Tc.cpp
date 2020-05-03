
#include "Tc.hpp"

#include <iostream>
#include <string>

#include "SDL2/SDL_image.h"
#include "../Display.hpp"
#include "../sdl_utils.hpp"

Tc::Tc(const int xpos, const int ypos): xpos(xpos), ypos(ypos)
{
   // load all textures associated with alt
   tex_back   = sdl_utils::load_texture("../assets/images/instruments/tc/tc_back.svg");
   tex_ball   = sdl_utils::load_texture("../assets/images/instruments/tc/tc_ball.svg");
   tex_face_1 = sdl_utils::load_texture("../assets/images/instruments/tc/tc_face_1.svg");
   tex_face_2 = sdl_utils::load_texture("../assets/images/instruments/tc/tc_face_1.svg");
   tex_mark   = sdl_utils::load_texture("../assets/images/instruments/tc/tc_mark.svg");
   tex_case   = sdl_utils::load_texture("../assets/images/instruments/tc/tc_case.svg");

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

Tc::~Tc()
{
   SDL_DestroyTexture(tex_back);
   SDL_DestroyTexture(tex_ball);
   SDL_DestroyTexture(tex_face_1);
   SDL_DestroyTexture(tex_face_2);
   SDL_DestroyTexture(tex_mark);
   SDL_DestroyTexture(tex_case);
}

void Tc::update(const float dt)
{
}

void Tc::render()
{
   SDL_RenderCopy(Display::renderer, tex_back,   &src_rect, &dest_rect);
   SDL_RenderCopy(Display::renderer, tex_ball,   &src_rect, &dest_rect);
   SDL_RenderCopy(Display::renderer, tex_face_1, &src_rect, &dest_rect);
   SDL_RenderCopy(Display::renderer, tex_face_1, &src_rect, &dest_rect);
   SDL_RenderCopy(Display::renderer, tex_mark,   &src_rect, &dest_rect);
   SDL_RenderCopy(Display::renderer, tex_case,   &src_rect, &dest_rect);
}


