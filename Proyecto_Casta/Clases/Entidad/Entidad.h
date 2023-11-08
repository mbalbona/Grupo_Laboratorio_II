#pragma once
#include <iostream>
#include <SDL2/SDL_image.h>
#include "Entidad.h"
#include "SDL.h"
#include "Calculos.h"

/**
CLASE ENTIDAD

CLASE ABSTRACTA QUE PROPORCIONA UNA BASE PARA CREAR OBJETOS QUE SE PUEDEN RENDERIZAR EN UNA VENTANA SDL.
LO QUE SIGNIFICA  QUE NO SE PUEDE INSTANCIAR DIRECTAMENTE. PARA CREAR UNA ENTIDAD, SE DEBE CREAR UNA CLASE DERIVADA DE Entidad QUE IMPLEMENTE LA FUNCION render().
*/

class Entidad
{
    public:
        Entidad(Vector, SDL_Texture *);

        ///GETTERS
        Vector &getPos(){return pos;}
        SDL_Texture *getTextura(void){return tex;}
        SDL_Rect getFrameActual(void){return frame_actual;}

    private:
        Vector pos;
        SDL_Rect frame_actual;
        SDL_Texture *tex;

};


