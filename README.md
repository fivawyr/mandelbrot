## Overview
- small mandelbrot implementation with SDL2 
- mandelbrot is one of the core concepts of complex numbers, doubling - kaskaden (chaotic elements) and represents bifurcation concepts as VD and CFD!


### Run
```
brew install sdl2 
```
```
git clone https://github.com/fivawyr/tiny_mandelbrot.git
cd # where ever you clone this repo
c++ main.cpp -I/opt/homebrew/include $(sdl2-config --libs) -o main && ./main
./mandelbrot
```

- TODO: Screenshot of finished simulaion

### Ressources
- [SDL2 Documenation](https://wiki.libsdl.org/SDL2/FrontPage)
- [man complex.h](https://man7.org/linux/man-pages/man0/complex.h.0p.html)
- [Daniel Hirsch YT](https://www.youtube.com/watch?v=9r6JV3hhSmk&t=1985s)
- [Mandelbrot Wikipedia](https://de.wikipedia.org/wiki/Mandelbrot-Menge)
