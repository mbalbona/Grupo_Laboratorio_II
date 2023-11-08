#include <iostream>
#include "Entidad.h"
#include "SDL.h"
#include <SDL2/SDL_image.h>

using namespace std;

Entidad::Entidad(Vector p_pos, SDL_Texture *textura)
:pos(p_pos), tex(textura)
{
    frame_actual.x = 0;
    frame_actual.y = 0;
    frame_actual.w = 256;
    frame_actual.h = 240;

}

