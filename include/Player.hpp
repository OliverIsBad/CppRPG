
#pragma once

#include "Entity.hpp"
#include <SDL2/SDL_render.h>
#include <vector>

class Player : public Entity {

public:

    Player(float p_x, float p_y, SDL_Texture* p_tex, int p_sheetW, int p_sheetH, int p_frameH, int p_frameW);
    void update();
    void move(const SDL_Event& event);
    bool checkBounds(int x, int p_xBounds);

private:
    std::vector<SDL_Rect> frames;
    int currentFrameIndex = 0;
    int frameWidth, frameHeight;
    int updateCounter = 0; 
};
