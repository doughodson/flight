
#ifndef __Vsi_HPP__
#define __Vsi_HPP__


#include "../Instrument.hpp"

#include "SDL2/SDL.h"

//---------------------------------------------------
// Class: Vsi
// Description: Vertical Speed Indicator
//---------------------------------------------------
class Vsi: public Instrument
{
public:
   Vsi(int xpos, int ypos);
   ~Vsi();

   void update(const float dt) override;
   void render() override;

private:
   int xpos{};
   int ypos{};
   float climb_rate{};

   SDL_Texture* tex_face{};
   SDL_Texture* tex_hand{};
   SDL_Texture* tex_case{};

   SDL_Rect src_rect, dest_rect;
};


#endif

