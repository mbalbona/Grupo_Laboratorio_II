#pragma once
#include <iostream>
#include "Entidad.h"
#include "SDL.h"
#include <SDL2/SDL_image.h>

/**
CLASE ENTIDAD

CLASE ABSTRACTA QUE PROPORCIONA UNA BASE PARA CREAR OBJETOS QUE SE PUEDEN RENDERIZAR EN UNA VENTANA SDL.
LO QUE SIGNIFICA  QUE NO SE PUEDE INSTANCIAR DIRECTAMENTE. PARA CREAR UNA ENTIDAD, SE DEBE CREAR UNA CLASE DERIVADA DE Entidad QUE IMPLEMENTE LA FUNCION render().
*/

class Entidad
{
    public:
        Entidad(float, float, SDL_Texture *);

        ///GETTERS
        float getX(void){return x;}
        float getY(void){return y;}
        SDL_Texture *getTextura(void){return tex;}
        SDL_Rect getFrameActual(void){return frame_actual;}
    private:
        float x, y;
        SDL_Rect frame_actual;
        SDL_Texture *tex;
};


