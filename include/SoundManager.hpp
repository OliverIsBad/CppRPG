#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <string.h>

class Soundmanager {
    

public:
    static void init();
    static void playLaser();
    static void cleanup();

private:
    static Mix_Chunk* laser;

};
