#include "Calculos.h"
#include "SDL.h"
#include <SDL2/SDL_image.h>

Vector::Vector()
: x(0.0f), y(0.0f)
{}

Vector::Vector(float p_x, float p_y)
: x(p_x), y(p_y)
{}

void Vector::mostrar()
{
    std::cout<< x << " " << y << std::endl;
}

float tiempoEnSegundos()
{
    float t = SDL_GetTicks();
    t *= 0.001f;

    return t;
}
