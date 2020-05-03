
#ifndef __Alt_HPP__
#define __Alt_HPP__


#include "../Instrument.hpp"

#include "SDL2/SDL.h"

//---------------------------------------------------
// Class: Alt
// Description: Barometric Altimeter
//---------------------------------------------------
class Alt: public Instrument
{
public:
   Alt(int xpos, int ypos);
   ~Alt();

   void update(const float dt) override;
   void render() override;

private:
   int xpos{};
   int ypos{};
   float altitude{};
   float pressure{28.0f};

   SDL_Texture* texFace_1{};
   SDL_Texture* texFace_2{};
   SDL_Texture* texFace_3{};
   SDL_Texture* texHand_1{};
   SDL_Texture* texHand_2{};
   SDL_Texture* texCase{};
   SDL_Rect src_rect, dest_rect;
};


#endif

