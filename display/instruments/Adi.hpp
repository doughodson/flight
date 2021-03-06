
#ifndef __Adi_HPP__
#define __Adi_HPP__


#include "../Instrument.hpp"

#include "SDL2/SDL.h"

//---------------------------------------------------
// Class: Adi
// Description: Attitude Direction Indicator
//---------------------------------------------------
class Adi: public Instrument
{
public:
   Adi(int xpos, int ypos);
   ~Adi();

   void update(const float dt) override;
   void render() override;

private:
   int xpos{};
   int ypos{};
   double angle{};

   SDL_Texture* tex_back{};
   SDL_Texture* tex_face{};
   SDL_Texture* tex_ring{};
   SDL_Texture* tex_case{};

   SDL_Rect src_rect, dest_rect;
};


#endif

