
#include "Alt.hpp"

#include <iostream>
#include <string>
#include <cmath>

#include "SDL2/SDL_image.h"
#include "../Display.hpp"
#include "../sdl_utils.hpp"

Alt::Alt(const int xpos, const int ypos): xpos(xpos), ypos(ypos)
{
   // load all textures associated with alt
   tex_face_1 = sdl_utils::load_texture("../assets/images/instruments/alt/alt_face_1.svg");
   tex_face_2 = sdl_utils::load_texture("../assets/images/instruments/alt/alt_face_2.svg");
   tex_face_3 = sdl_utils::load_texture("../assets/images/instruments/alt/alt_face_3.svg");
   tex_hand_1 = sdl_utils::load_texture("../assets/images/instruments/alt/alt_hand_1.svg");
   tex_hand_2 = sdl_utils::load_texture("../assets/images/instruments/alt/alt_hand_2.svg");
   tex_case   = sdl_utils::load_texture("../assets/images/instruments/alt/alt_case.svg");

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

Alt::~Alt()
{
   SDL_DestroyTexture(tex_face_1);
   SDL_DestroyTexture(tex_face_2);
   SDL_DestroyTexture(tex_face_3);
   SDL_DestroyTexture(tex_hand_1);
   SDL_DestroyTexture(tex_hand_2);
   SDL_DestroyTexture(tex_case);
}

void Alt::update(const float dt)
{
   altitude += 5;
}

void Alt::render()
{
   const int alt{static_cast<int>(std::ceil(altitude + 0.5))};

   const float angleH1{altitude * 0.036f};
   const float angleH2{(alt % 1000)*0.36f};
   const float angleF1{(pressure - 28.0f)*100.0f};
   const float angleF3{altitude * 0.0036f};

   SDL_RenderCopyEx(Display::renderer, tex_face_1, &src_rect, &dest_rect, -angleF1, 0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, tex_face_2, &src_rect, &dest_rect,        0, 0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, tex_face_3, &src_rect, &dest_rect,  angleF3,  0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, tex_hand_1, &src_rect, &dest_rect,  angleH1,  0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, tex_hand_2, &src_rect, &dest_rect,  angleH2,  0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, tex_case,   &src_rect, &dest_rect,        0,  0, SDL_FLIP_NONE);
}


