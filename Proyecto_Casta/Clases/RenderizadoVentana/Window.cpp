#include "SDL.h"
#include <SDL2/SDL_image.h>
#include "Window.h"

Window::Window()
{
    _window = SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

Window::~Window()
{
    //dtor
}
