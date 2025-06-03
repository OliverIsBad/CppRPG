#pragma once

#include <SDL2/SDL.h>
#include "Entity.hpp"

class Food : public Entity {

public:
    Food(float p_x, float p_y, SDL_Texture* p_tex);
    ~Food();
    float setPos();
    void move();
    bool checkBounds(int bounds);
};
