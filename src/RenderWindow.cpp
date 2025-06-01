
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <cstddef>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h) :window(NULL), renderer(NULL) {
     window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL) {
        std::cout << "Failed to Load texture. Error: " << SDL_GetError() << std::endl;
    }

    return texture;
}

void RenderWindow::cleanUp() {
    SDL_DestroyWindow(window);
}

void RenderWindow::clear() {
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity) {
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.getX() * 5;
    dst.y = p_entity.getY() * 5;
    dst.w = p_entity.getCurrentFrame().w * 5;
    dst.h = p_entity.getCurrentFrame().h * 5;

    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

void RenderWindow::display() {
    SDL_RenderPresent(renderer);
}

void RenderWindow::renderCheckerboard(int tileSize, int screenWidth, int screenHeight) {
    SDL_Rect rect;
    rect.w = tileSize;
    rect.h = tileSize;

    for (int y = 0; y < screenHeight; y += tileSize) {
        for (int x = 0; x < screenWidth; x += tileSize) {
            rect.x = x;
            rect.y = y;

            // Schachbrettmuster: abwechselnde Farben
          
            if (((x / tileSize) + (y / tileSize)) % 2 == 0) {
                SDL_SetRenderDrawColor(renderer, 180, 150, 200, 255); // Dunkellila (Indigo)
            } else {
                SDL_SetRenderDrawColor(renderer, 200, 170, 220, 255); // Helllila (BlueViolet)
            }


            SDL_RenderFillRect(renderer, &rect);
        }
    }
}
