
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <vector>
#include "Utils.hpp"

// Splits spritesheet
std::vector<SDL_Rect> splitSpriteSheet(int p_frameW, int p_frameH, int p_sheetW, int p_sheetH) {
    std::vector<SDL_Rect> frames;

    int cols = p_sheetW / p_frameW;
    int rows = p_sheetH / p_frameH;
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            SDL_Rect frame = {
                i * p_frameW,
                j * p_frameH,
                p_frameW,
                p_frameH
            };
            frames.push_back(frame);
        }
    }
    return frames;
}
