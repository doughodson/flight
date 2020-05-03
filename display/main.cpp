
#include "SDL2/SDL.h"

#include "Display.hpp"

#include <iostream>
#include <memory>
#include <cmath>

int main() {

   std::cout << "Creating Display" << std::endl;
   auto display = std::make_unique<Display>("Display", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

   display->load_level();

   float fps{10};                     // frame rate (e.g., 30 frames per seconds)
   float delta_time{1.0f/fps};        // in seconds (e.g., 30 Hz => 0.03333)

   std::cout << "Starting game loop" << std::endl;
   while (display->running()) {
      Uint64 start_time = SDL_GetPerformanceCounter();
      display->handle_events();
      display->update(delta_time);
      display->render();
      Uint64 end_time = SDL_GetPerformanceCounter();
      float elapsed_time = (end_time-start_time) / static_cast<float>(SDL_GetPerformanceFrequency() * 1000.0f); // (secs)
      if (elapsed_time < delta_time) {
         SDL_Delay(static_cast<Uint32>(std::floor((delta_time - elapsed_time)/1000.0f)));  // (ms)
      }
      //std::cout << "." <<std::flush;
   }
   return 0;
}


