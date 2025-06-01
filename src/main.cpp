#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
#include "Player.hpp"
#include "Entity.hpp"
#include "RenderWindow.hpp"

// Renders all Entities
void renderEntities(RenderWindow& window, Entity *entities, int count) {
        for (int i = 0; i < count; i ++) {
            window.render(entities[i]);
        }
}

int main(int argv, char* args[]) {

    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cout << "SDL INIT has failed. SDL_ERROR: " << SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG))) {
        std::cout << "IMG_INIT has failed. Error: " << SDL_GetError() << std::endl;
    }

    const int screenWidth = 1280;
    const int screenHeight = 720;

    RenderWindow window("GAME v1.0", screenWidth, screenHeight);

    SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");
    SDL_Texture* playerTexture = window.loadTexture("res/gfx/playerIdle.png");

    Player player(100, 112, playerTexture, 64,64,32,32);
    Entity entities[3] = {Entity(0,0,grassTexture), Entity(100,100,grassTexture), Entity(150,150,grassTexture)};

    bool gameRunning = true;
    SDL_Event event;

    const int FPS = 60;
    const int frameDelay = 1000/ FPS;
    
    while (gameRunning) {
        Uint32 frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                gameRunning = false;
            }
            player.move(event);
        }

        window.clear();
        window.renderCheckerboard(64, screenWidth, screenHeight);
                //renderEntities(window, entities, std::size(entities));
        window.render(player);
        player.update();
        window.display();

        Uint32 frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    window.cleanUp();
    SDL_Quit();
    return 0;
}
