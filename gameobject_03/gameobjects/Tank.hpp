#ifndef __Tank_HPP__
#define __Tank_HPP__

#include "../GameObject.hpp"
#include "SDL2/SDL.h"

class Tank: public GameObject {
public:
   Tank(const float xpos, const float ypos,
        const float xvel, const float yvel);
   ~Tank();

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