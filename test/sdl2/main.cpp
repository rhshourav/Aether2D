#include <iostream>
#include <SDL2/SDL.h>

// Returns true if there is a collision, false if there is not
bool checkCollision(SDL_Rect a, SDL_Rect b) {
    if (a.x + a.w <= b.x) return false; 
    if (a.x >= b.x + b.w) return false; 
    if (a.y + a.h <= b.y) return false; 
    if (a.y >= b.y + b.h) return false; 
    return true; 
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Initialization Failed! Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Aether2D Engine", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        800, 400, 
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Player setup: { x, y, width, height }
    SDL_Rect player = { 350, 150, 50, 50 };
    int speed = 5;

    // Wall setup: A wide, flat platform
    SDL_Rect wall = { 200, 250, 400, 40 };

    bool isRunning = true;
    SDL_Event event;

    while (isRunning) {
        // Save the old position BEFORE we move the player
        int oldX = player.x;
        int oldY = player.y;

        // 1. INPUT
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_RIGHT: player.x += speed; break;
                    case SDLK_LEFT:  player.x -= speed; break;
                    case SDLK_UP:    player.y -= speed; break;
                    case SDLK_DOWN:  player.y += speed; break;
                }
            }
        }

        // 2. COLLISION DETECTION
        // Wall collision
        if (checkCollision(player, wall)) {
            player.x = oldX;
            player.y = oldY;
        }

        // Screen boundary collisions
        if (player.x < 0) {
            player.x = 0; // Left edge
        }
        if (player.y < 0) {
            player.y = 0; // Top edge
        }
        if (player.x + player.w > 800) {
            player.x = 800 - player.w; // Right edge
        }
        if (player.y + player.h > 400) {
            player.y = 400 - player.h; // Bottom edge
        }

        // 3. RENDER
        SDL_SetRenderDrawColor(renderer, 20, 80, 100, 255);
        SDL_RenderClear(renderer);

        // Draw Player (Red)
        SDL_SetRenderDrawColor(renderer, 255, 50, 50, 255);
        SDL_RenderFillRect(renderer, &player);

        // Draw Wall (Green)
        SDL_SetRenderDrawColor(renderer, 50, 255, 50, 255);
        SDL_RenderFillRect(renderer, &wall);

        SDL_RenderPresent(renderer);
        SDL_Delay(16); 
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}