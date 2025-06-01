#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <vector>
#include "Player.hpp"
#include "Entity.hpp"
#include "Utils.hpp"

Player::Player(float p_x, float p_y, SDL_Texture* p_tex, int p_sheetW, int p_sheetH, int p_frameH, int p_frameW) : Entity(p_x, p_y, p_tex), frameWidth(p_frameW), frameHeight(p_frameH) {
    updateCounter = 0;
    frames = splitSpriteSheet(p_frameW, p_frameH, p_sheetW, p_sheetH);

    if (!frames.empty()) {
        setCurrentFrame(frames[0]);
    }

}

void Player::update() {
    updateCounter++;
    if(updateCounter >= 10) {
        currentFrameIndex = (currentFrameIndex + 1) % frames.size();
        setCurrentFrame(frames[currentFrameIndex]);
        updateCounter = 0;
    }
}

void Player::move(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        SDL_Keycode key = event.key.keysym.sym;
        int newX = getX();

        switch (key) {
            case SDLK_a:
                newX -= 5;
                break;
            case SDLK_d:
                newX += 5;
                break;
        }

        if (!checkBounds(newX, 230)) {
            setX(newX);
        }
    }
}

bool Player::checkBounds(int x, int p_xBounds) {
return x < -6 || x > p_xBounds;
}
