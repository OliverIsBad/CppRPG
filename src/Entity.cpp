
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include "Entity.hpp"

Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex)
    :x(p_x), y(p_y), tex(p_tex) {
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;

}

float Entity::getX() {
    return x;
}

float Entity::getY() {
    return y;
}

SDL_Texture* Entity::getTex() {
    return tex;
}

SDL_Rect Entity::getCurrentFrame() {
    return currentFrame;
}

void Entity::setX(int p_x) {
    x = p_x;
}

void Entity::setY(int p_y) {
    y = p_y;
}

void Entity::setCurrentFrame(const SDL_Rect& frame) {
    currentFrame = frame;
}

