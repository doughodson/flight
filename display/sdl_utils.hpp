#ifndef __sdl_utils_HPP__
#define __sdl_utils_HPP__

#include "SDL2/SDL.h"

namespace sdl_utils
{

// load image and convert to texture
SDL_Texture* load_texture(const char* filename);

// draw texture from using source rect to destination rect
void draw(SDL_Texture*, SDL_Rect src, SDL_Rect dest);

}

#endif

