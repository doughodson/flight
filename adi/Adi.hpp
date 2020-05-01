
#ifndef __Adi_HPP__
#define __Adi_HPP__

#include "SDL2/SDL.h"

#include <vector>
#include <memory>

class Adi
{
public:
   Adi(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
   ~Adi();

   void load_level();

   void handle_events();
   void update(const float dt);
   void render();

   bool running()                { return is_running; }

   static SDL_Renderer* renderer;
   static SDL_Window* window;

private:
   bool is_running{};
   double angle{};

   SDL_Texture* texBack{};
   SDL_Texture* texFace{};
   SDL_Texture* texRing{};
   SDL_Texture* texCase{};
   SDL_Rect src_rect, dest_rect;
};


#endif

