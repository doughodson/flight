
#ifndef __Asi_HPP__
#define __Asi_HPP__


#include "Instrument.hpp"

#include "SDL2/SDL.h"

//---------------------------------------------------
// Class: Asi
// Description: Airspeed Indicator
//---------------------------------------------------
class Asi: public Instrument
{
public:
   Asi(int xpos, int ypos);
   ~Asi();

   void update(const float dt) override;
   void render() override;

private:
   int xpos{};
   int ypos{};

   SDL_Texture* texFace_1{};
   SDL_Texture* texFace_2{};
   SDL_Texture* texFace_3{};
   SDL_Texture* texHand_1{};
   SDL_Texture* texHand_2{};
   SDL_Texture* texCase{};
   SDL_Rect src_rect, dest_rect;
};


#endif

