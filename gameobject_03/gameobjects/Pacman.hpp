#ifndef __Pacman_HPP__
#define __Pacman_HPP__

#include "../GameObject.hpp"
#include "SDL2/SDL.h"

class Pacman: public GameObject {
public:
   Pacman(const float xpos, const float ypos,
          const float xvel, const float yvel);
   ~Pacman();

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