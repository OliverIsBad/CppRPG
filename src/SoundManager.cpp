#include <SDL2/SDL_mixer.h>
#include <string>
#include "SoundManager.hpp"

void Soundmanager::init() {
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Mix_openaudio failed: " << Mix_GetError() << "\n";
    }

    laser = Mix_LoadWAV("assets/sounds/laser.wav");

    if (!laser) {
        std::cerr << "Failed to Load laser sound" << Mix_GetError() << "\n";
    }
}

void Soundmanager::playLaser() {
    if (laser) {
        Mix_PlayChannel(-1, laser, 0);
    }
}

void Soundmanager::cleanup() {
    if(laser) {
        Mix_FreeChunk(laser);
        laser = nullptr;
    }
    Mix_CloseAudio();
}
