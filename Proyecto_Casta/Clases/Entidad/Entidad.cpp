#include <iostream>
#include "Entidad.h"
#include "SDL.h"
#include <SDL2/SDL_image.h>

using namespace std;

Entidad::Entidad(float p_x, float p_y, SDL_Texture *textura)
: x(p_x), y(p_y), tex(textura)
{
    frame_actual.x = 0;
    frame_actual.y = 0;
    frame_actual.w = 256;
    frame_actual.h = 240;


}
