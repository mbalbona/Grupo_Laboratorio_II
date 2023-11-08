#pragma once
#include <iostream>
#include <vector>
#include "SDL.h"
#include <SDL2/SDL_image.h>

#include "Entidad.h"

/**
CLASE RENDERERWINDOW

CLASE ENCARGADA DE CONTROLAR, ELIMINAR Y CREAR VENTANAS SDL DENTRO DEL PROGRAMA
*/
class RendererWindow
{
    public:

        RendererWindow(const char *titulo, int largo, int ancho);       ///CONSTRUCTOR QUE TOMA COMO PARAMETRO UN TITULO Y LAS DIMENSIONES DESEADAS


        int getRefreshRate();
        SDL_Renderer getRenderer(){return _renderer;}
        void Update(double elapsed_seconds, Entidad &entid);            ///VACIA EL BUFER DE RENDERIZADO DE LA VENTANA
        void Release();                                                 ///LIBERA LOS RECURSOS UTILIZADO AL FINALIZAR EL PROGRAMA, ES DECIR LA MEMORIA UTILIZADA POR LA VENTANA.


    private:
        SDL_Window *window;         ///VARIABLE CONTROLADORA DE LAS PROPIEDADES DE LAS VENTANAS
        SDL_Renderer *_renderer;
        int frame_index;
};


