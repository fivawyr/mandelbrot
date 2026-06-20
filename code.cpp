#include <SDL.h>
#include <SDL_events.h>
#include <SDL_video.h>
#include <arm_neon.h>
#include <iostream>
#include <cstdint>

using namespace std;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef vector<i64> vi;
typedef float16_t f16;

#define WIDTH 600
#define HEIGHT 500

//TODO adding complex numbers into bl_mandelbrot and passing parameters
i64 bl_mandelbrot();

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cerr << "The SDL init didnt work because: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window *pwindow = SDL_CreateWindow("Mandelbrot Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (!pwindow) {
        cerr << "Error at the creation of the Window: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }
    SDL_Delay(300);

    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
    if (!psurface) {
        cerr << "Error at the surface creation: " << SDL_GetError() << endl;
        SDL_DestroyWindow(pwindow);
        SDL_Quit();
        return 1;
    } 

    i16 application_running = 1;
    while (application_running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    application_running = 0;
                    break;
                default:
                    break;
            }
        }

        SDL_Rect rect = {0, 0, 100, 100};
        i32 white = SDL_MapRGB(psurface->format, 255, 255, 255);
        SDL_FillRect(psurface, &rect, white);
        SDL_UpdateWindowSurface(pwindow);

        SDL_Delay(20); 
    }

    SDL_DestroyWindow(pwindow);
    SDL_Quit();
    return 0;
}

i64 bl_mandelbrot(i64) {
    //TODO    
}
