
#ifndef __Display_HPP__
#define __Display_HPP__

#include "SDL2/SDL.h"

#include <memory>

#include "Instrument.hpp"

class Display
{
public:
   Display(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
   ~Display();

   void load_level();

   void handle_events();
   void update(const float dt);
   void render();

   bool running()                { return is_running; }

   static SDL_Renderer* renderer;
   static SDL_Window* window;

private:
   bool is_running{};

   std::unique_ptr<Instrument> adi{};
   std::unique_ptr<Instrument> alt{};
};


#endif


