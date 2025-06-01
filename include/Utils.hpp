#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <vector>

std::vector<SDL_Rect> splitSpriteSheet(int p_frameW, int p_frameH, int p_sheetW, int p_sheetH);
