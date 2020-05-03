
#ifndef __Tc_HPP__
#define __Tc_HPP__


#include "../Instrument.hpp"

#include "SDL2/SDL.h"

//---------------------------------------------------
// Class: Tc
// Description: Turn Coordinator
//---------------------------------------------------
class Tc: public Instrument
{
public:
   Tc(int xpos, int ypos);
   ~Tc();

   void update(const float dt) override;
   void render() override;

private:
   int xpos{};
   int ypos{};

   SDL_Texture* tex_back{};
   SDL_Texture* tex_ball{};
   SDL_Texture* tex_face_1{};
   SDL_Texture* tex_face_2{};
   SDL_Texture* tex_mark{};
   SDL_Texture* tex_case{};

   SDL_Rect src_rect, dest_rect;
};


#endif

