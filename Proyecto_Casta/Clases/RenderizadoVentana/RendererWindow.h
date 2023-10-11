#ifndef RENDERERWINDOW_H
#define RENDERERWINDOW_H

class RendererWindow
{
    public:

        RendererWindow(const char *titulo, int largo, int ancho);       ///CONSTRUCTOR QUE TOMA COMO PARAMETRO UN TITULO Y LAS DIMENSIONES DESEADAS
        SDL_Texture *cargar_textura(const char *);                      ///FUNCION ENCARGADA DE CARGAR LAS TEXTURAS/IMAGENES QUE IMPLEMENTAREMOS
        void limpiar();                                                 ///FUNCION ENCARGADA DE LIMPIAR LAS VENTANAS CREADAS CUANDO FINALICE LA EJECUCION DEL PROGRAMA.

    private:
        SDL_Window *window;         ///VARIABLE CONTROLADORA DE LAS PROPIEDADES DE LAS VENTANAS
        SDL_Renderer *renderer;     ///VARIABLE ALMACENADORA DE RENDERIZAR LA VENTANA
};

#endif // RENDERERWINDOW_H
