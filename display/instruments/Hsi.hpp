
#ifndef __Hsi_HPP__
#define __Hsi_HPP__


#include "../Instrument.hpp"

#include "SDL2/SDL.h"

//---------------------------------------------------
// Class: Hsi
// Description: Horizonal Airspeed Indicator
//---------------------------------------------------
class Hsi: public Instrument
{
public:
   Hsi(int xpos, int ypos);
   ~Hsi();

   void update(const float dt) override;
   void render() override;

private:
   int xpos{};
   int ypos{};
   float heading{};

   SDL_Texture* tex_face{};
   SDL_Texture* tex_case{};

   SDL_Rect src_rect, dest_rect;
};


#endif

