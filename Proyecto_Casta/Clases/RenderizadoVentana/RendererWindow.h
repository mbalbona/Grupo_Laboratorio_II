#pragma once
#include <iostream>
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
        SDL_Texture *cargar_textura(const char *);                      ///FUNCION ENCARGADA DE CARGAR LAS TEXTURAS/IMAGENES QUE IMPLEMENTAREMOS

        int getTasaDeRefresco();

        void vaciar();                                                  ///VACIA EL BUFER DE RENDERIZADO DE LA VENTANA
        void renderizar(Entidad &);                                     ///RENDERIZA LAS TEXTURAS COLOCADAS, RECIBIENDO UNA REFERENCIA QUE CONTIENE LA DIRECCION DE LA IMAGEN
        void mostrar();                                                 ///MUESTRAN LA IMAGEN
        void limpiar();                                                 ///LIBERA LOS RECURSOS UTILIZADO AL FINALIZAR EL PROGRAMA, ES DECIR LA MEMORIA UTILIZADA POR LA VENTANA.
        //bool mover(vector<Entidad> *, );


    private:
        SDL_Window *window;         ///VARIABLE CONTROLADORA DE LAS PROPIEDADES DE LAS VENTANAS
        SDL_Renderer *renderer;     ///VARIABLE ALMACENADORA DE RENDERIZAR LA VENTANA
};


