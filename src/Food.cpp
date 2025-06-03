
#include <SDL2/SDL.h>
#include <cstdlib>
#include "Entity.hpp"
#include "Food.hpp"
#include <iostream>


Food::Food(float p_x, float p_y, SDL_Texture* p_tex): Entity(p_x, p_y, p_tex) {
    setCurrentFrame({0,0,16,16});
    int randPos = setPos();
    setX(randPos);
}

float Food::setPos() {
    return rand() % 231;
}

void  Food::move() {
    setY(getY() +2);
}

bool Food::checkBounds(int bounds) {
    if (getY() > bounds) {
        return true;
    } else return false;
}
