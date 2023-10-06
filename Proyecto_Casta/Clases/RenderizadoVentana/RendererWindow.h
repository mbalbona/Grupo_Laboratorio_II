#ifndef RENDERERWINDOW_H
#define RENDERERWINDOW_H


class RendererWindow
{
    public:
        RendererWindow(const char *titulo, int largo, int ancho);

    private:
        SDL_Window *window;         ///VARIABLE CONTROLADORA DE LAS PROPIEDADES DE LAS VENTANAS
        SDL_Renderer *renderer;     ///VARIABLE ALMACENADORA DE LOS FRAMES POR SEGUNDO
};

#endif // RENDERERWINDOW_H
