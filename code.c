#include <SDL_timer.h>
#include <SDL_video.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#define WIDTH 600
#define HEIGHT 500

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindow("Mandelbrot Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Delay(3000);
}
