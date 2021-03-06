
#ifndef __Asi_HPP__
#define __Asi_HPP__


#include "../Instrument.hpp"

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
   double angle{};

   SDL_Texture* texFace{};
   SDL_Texture* texHand{};
   SDL_Texture* texCase{};
   SDL_Rect src_rect, dest_rect;
};


#endif

