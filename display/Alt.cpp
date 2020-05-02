
#include "Alt.hpp"

#include <iostream>
#include <string>
#include <cmath>

#include "SDL2/SDL_image.h"
#include "Display.hpp"
#include "sdl_utils.hpp"

Alt::Alt(const int xpos, const int ypos): xpos(xpos), ypos(ypos)
{
   // load all textures associated with alt
   texFace_1 = sdl_utils::load_texture("../assets/images/instruments/alt/alt_face_1.svg");
   texFace_2 = sdl_utils::load_texture("../assets/images/instruments/alt/alt_face_2.svg");
   texFace_3 = sdl_utils::load_texture("../assets/images/instruments/alt/alt_face_3.svg");
   texHand_1 = sdl_utils::load_texture("../assets/images/instruments/alt/alt_hand_1.svg");
   texHand_2 = sdl_utils::load_texture("../assets/images/instruments/alt/alt_hand_2.svg");
   texCase = sdl_utils::load_texture("../assets/images/instruments/alt/alt_case.svg");

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
   SDL_DestroyTexture(texFace_1);
   SDL_DestroyTexture(texFace_2);
   SDL_DestroyTexture(texFace_3);
   SDL_DestroyTexture(texHand_1);
   SDL_DestroyTexture(texHand_2);
   SDL_DestroyTexture(texCase);
}

void Alt::update(const float dt)
{
   altitude += 5;
}

void Alt::render()
{
   int alt = std::ceil( altitude + 0.5 );

   float angleH1{altitude * 0.036f};
   float angleH2{(alt % 1000)*0.36f};
   float angleF1{(pressure - 28.0f)*100.0f};
   float angleF3{altitude * 0.0036f};

   SDL_RenderCopyEx(Display::renderer, texFace_1, &src_rect, &dest_rect, -angleF1, 0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, texFace_2, &src_rect, &dest_rect,        0, 0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, texFace_3, &src_rect, &dest_rect, angleF3,  0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, texHand_1, &src_rect, &dest_rect, angleH1,  0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, texHand_2, &src_rect, &dest_rect, angleH2,  0, SDL_FLIP_NONE);
   SDL_RenderCopyEx(Display::renderer, texCase,   &src_rect, &dest_rect,       0,  0, SDL_FLIP_NONE);
}


