
#include <SDL2/SDL.h>
#include <vector>
#include "Player.hpp"
#include "Entity.hpp"
#include "Utils.hpp"

Player::Player(float p_x, float p_y, SDL_Texture* p_tex, int p_sheetW, int p_sheetH, int p_frameH, int p_frameW) : Entity(p_x, p_y, p_tex), frameWidth(p_frameW), frameHeight(p_frameH) {
    frames = splitSpriteSheet(p_frameW, p_frameH, p_sheetW, p_sheetH);

    if (!frames.empty()) {
        setCurrentFrame(frames[0]);
    }
}

void Player::update() {
    currentFrameIndex = (currentFrameIndex + 1) % frames.size();
    setCurrentFrame(frames[currentFrameIndex]);
}
