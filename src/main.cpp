#include <iostream>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640
#define WHITE 0xffffff
#define YELLOW 0xffff00
#define RED 0xff0000
#define GREEN 0x00ff00
#define BLACK 0x000000

//Draw the circle
//[TO DO] Optimize this function and add it to a class
void FillCircle(SDL_Surface* surface, int x, int y, int radius, Uint32 color) {
    double radius_squared = radius * radius;
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            if (i * i + j * j <= radius_squared) {
                SDL_Rect rect = {x + i, y + j, 1, 1};
                SDL_FillRect(surface, &rect, color);
            }
        }
    }
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Raytracing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    
    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
    SDL_Rect erase_rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};


    int simulation_run = 1;
    Sint32 circle_x = 100;
    Sint32 circle_y = 100;
    while (simulation_run) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                simulation_run = 0;
            }
            if (event.type == SDL_MOUSEMOTION && event.motion.state == SDL_BUTTON_LEFT) {
                circle_x = event.motion.x;
                circle_y = event.motion.y;
            }
        }
        SDL_FillRect(screenSurface, &erase_rect, BLACK); //erase te old position of the  main circle
        FillCircle(screenSurface, circle_x, circle_y, 50, WHITE); //draw the main circle
        FillCircle(screenSurface, 320, 320, 10, YELLOW); //draw the light source

        SDL_UpdateWindowSurface(window);
        SDL_Delay(10);

    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}