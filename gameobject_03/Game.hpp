
#ifndef __Game_HPP__
#define __Game_HPP__

#include "SDL2/SDL.h"
#include "GameObject.hpp"

#define SOL_ALL_SAFETIES_ON 1
#include "sol/sol.hpp"

#include <vector>
#include <memory>

class Game
{
public:
   Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
   ~Game();

   void load_level();

   void handle_events();
   void update(const float dt);
   void render();

   bool running()                { return is_running; }

   static SDL_Renderer* renderer;
   static SDL_Window* window;
   static sol::state lua;

private:
   int counter{};
   bool is_running{};
   std::vector<std::unique_ptr<GameObject>> game_objs;
};

#endif

