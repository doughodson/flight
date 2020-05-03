
#ifndef __Nav_HPP__
#define __Nav_HPP__

#include "../Instrument.hpp"

#include "SDL2/SDL.h"

//---------------------------------------------------
// Class: Nav
// Description: Navigation Display
//---------------------------------------------------
class Nav: public Instrument
{
public:
   Nav(int xpos, int ypos);
   ~Nav();

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

