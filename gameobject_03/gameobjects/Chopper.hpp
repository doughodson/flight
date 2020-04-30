#ifndef __Chopper_HPP__
#define __Chopper_HPP__

#include "../GameObject.hpp"
#include "SDL2/SDL.h"

class Chopper: public GameObject {
public:
   Chopper(const float xpos, const float ypos,
           const float xvel, const float yvel);
   ~Chopper();

   void update(const float dt) override;
   void render() override;

private:
   float xpos{};
   float ypos{};
   float xvel{};
   float yvel{};

   SDL_Texture* texture{};
   SDL_Rect src_rect, dest_rect;
};

#endif

