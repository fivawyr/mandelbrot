#include <SDL.h>
#include <SDL_events.h>
#include <SDL_pixels.h>
#include <SDL_stdinc.h>
#include <SDL_surface.h>
#include <SDL_video.h>
#include <arm_neon.h>
#include <arm_neon.h>
#include <iostream>
#include <cstdint>
#include <complex>
#include <vector>

using namespace std;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef vector<i64> vi;
typedef float16_t f16;

#define WIDTH 600
#define HEIGHT 500
#define MANDEL_LIMIT 1000

static constexpr double X_MIN = -2.5;
static constexpr double X_MAX = 1.0;
static constexpr double Y_MIN = -1.25;
static constexpr double Y_MAX = 1.25;

i64 bl_mandelbrot(double real, double imag);
void visualize_mandelbrot_screen(SDL_Surface *psurface);


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
    
    cout << "Rendering Mandelbrot \n";
    visualize_mandelbrot_screen(psurface);
    SDL_UpdateWindowSurface(pwindow);
    cout << "Finished the rendering process\n";
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
    }
    SDL_DestroyWindow(pwindow);
    SDL_Quit();
    return 0;
}

i64 bl_mandelbrot(double real, double imag) {
    const complex<double> c(real, imag);
    complex<double> z(0.0, 0.0);
 
    for (i32 i = 0; i < MANDEL_LIMIT; i++) {   
       z = z * z + c;
        if (norm(z) > 4.0)
            return i;
    }
    return MANDEL_LIMIT;  
}
 


void visualize_mandelbrot_screen(SDL_Surface *psurface) {
    SDL_LockSurface(psurface);
    const i32 pitch_px = psurface->pitch / sizeof(Uint32);
    Uint32 *pixels = reinterpret_cast<Uint32 *>(psurface->pixels);

    for (i32 y = 0; y < HEIGHT; y++) {
        const double imag = Y_MIN + static_cast<double>(y) / HEIGHT * (Y_MAX - Y_MIN);

        for (i32 x = 0; x < WIDTH; x++) {
            const double real = X_MIN + static_cast<double>(x) / WIDTH * (X_MAX - X_MIN);
            const i64 iter = bl_mandelbrot(real, imag);
            Uint8 r, g, b;
            if (iter == MANDEL_LIMIT) {
                r = g = b = 0;
            } else {
                const double t = static_cast<double>(iter) / MANDEL_LIMIT;
                r = static_cast<Uint8>(9.0  * (1 - t) * t * t * t * 255);
                g = static_cast<Uint8>(15.0 * (1 - t) * (1 - t) * t * t * 255);
                b = static_cast<Uint8>(8.5  * (1 - t) * (1 - t) * (1 - t) * t * 255);
            }

            pixels[y * pitch_px + x] = SDL_MapRGB(psurface->format, r, g, b);
        }
    }
    SDL_UnlockSurface(psurface);
}
