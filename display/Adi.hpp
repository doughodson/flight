
#ifndef __Adi_HPP__
#define __Adi_HPP__


#include "Instrument.hpp"

#include "SDL2/SDL.h"

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

   SDL_Texture* texBack{};
   SDL_Texture* texFace{};
   SDL_Texture* texRing{};
   SDL_Texture* texCase{};
   SDL_Rect src_rect, dest_rect;
};


#endif

