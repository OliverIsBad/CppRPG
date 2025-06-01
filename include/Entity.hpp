#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

class Entity {

public:
    Entity(float p_x, float p_y, SDL_Texture* p_tex);
    float getX();
    float getY();
    SDL_Texture* getTex();
    SDL_Rect getCurrentFrame();
    void setCurrentFrame(const SDL_Rect& frame);

private:
    float x, y;
    SDL_Rect currentFrame;
    SDL_Texture* tex;
};
