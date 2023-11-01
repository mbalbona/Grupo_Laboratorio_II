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
        SDL_Texture *loadTexture(const char *);                         ///FUNCION ENCARGADA DE CARGAR LAS TEXTURAS/IMAGENES QUE IMPLEMENTAREMOS


        int getRefreshRate();

        void update(double elapsed_seconds, Entidad &entid);            ///VACIA EL BUFER DE RENDERIZADO DE LA VENTANA

        void render(Entidad &entid);                                    ///MUESTRAN LA IMAGEN
        void release();                                                 ///LIBERA LOS RECURSOS UTILIZADO AL FINALIZAR EL PROGRAMA, ES DECIR LA MEMORIA UTILIZADA POR LA VENTANA.


    private:
        SDL_Window *window;         ///VARIABLE CONTROLADORA DE LAS PROPIEDADES DE LAS VENTANAS
        SDL_Renderer *renderer;     ///VARIABLE ALMACENADORA DE RENDERIZAR LA VENTANA
        int frame_index;
};


