#include <iostream>
#include "SDL.h"
#include <SDL2/SDL_image.h>
#include "RendererWindow.h"
#define fps 120                                        ///#define es una directiva del preprocesador que permite definir constantes y macros.

using namespace std;


RendererWindow::RendererWindow(const char *titulo, int largo, int ancho)
    : window(nullptr), renderer(nullptr)                    ///LISTA DE INICIALIZACION DE MIEMBROS:
                                                            ///PERMITE INICIALIZAR LOS MIEMBROS DE UNA CLASE EN EL CONSTRUCTOR DE LA CLASE.
                                                            ///LA LISTA DE INICIALIZACION DE MIEMBROS SE ESPECIFICA DESPUES DE LA LISTA DE PARAMETROS DEL CONSTRUCTOR,
                                                            ///Y ESTA COMPUESTA POR UNA LISTA DE INICIALIZADORES PARA LOS MIEMBROS DE LA CLASE, SEPARADOS POR COMAS.
{



    window = SDL_CreateWindow(titulo,                       ///CREACION DE VENTANA
                                SDL_WINDOWPOS_UNDEFINED,    ///Posicion de la ventana en eje X
                                SDL_WINDOWPOS_UNDEFINED,    ///Posicion de la ventana en eje Y
                                largo,                      ///Largo
                                ancho,                      ///Ancho
                                SDL_WINDOW_SHOWN            ///Comportamiento de la ventana
                                );

    if( window == nullptr ) cout << "LA VENTANA FALLO EN INICIALIZARSE! Error: " << SDL_GetError() <<endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); ///CREA EL RENDERIZADOR QUE UTILIZARA LA TARJETA GRAFICA QUE TENGA EL EQUIPO. EN CASO DE TENER.

    if( renderer == nullptr ) cout << "EL RENDERIZADOR FALLO EN INICIALIZARSE! Error: " << SDL_GetError() <<endl;
}

SDL_Texture* RendererWindow::cargar_textura(const char *direccion_archivo)
{
    SDL_Texture *texture = nullptr;                                     ///INICIALIZAMOS LA VARIABLE EN NULA PARA PODER IDENTIFICAR FACILMENTE SI HUBO ALGUN FALLO AL CARGAR
                                                                        ///LA IMAGEN

    texture = IMG_LoadTexture(renderer, direccion_archivo);             ///CARGAMOS LA TEXTURA Y LA COLOCAMOS DENTRO DE LA VARIABLE texture

    if(texture == nullptr) cout << "FALLO EN CARGAR TEXTURA! ERROR: " << SDL_GetError() << endl;

    return texture;                                                     ///RETORNAMOS EL PUNTERO CONTENEDOR DE LA IMAGEN PARA TRABAJAR CON ELLA Y POSTERIORMENTE MOSTRARLA
}


void RendererWindow::limpiar()
{
    SDL_DestroyWindow(window);
}

void RendererWindow::vaciar()
{
    SDL_RenderClear(renderer);
}

void RendererWindow::renderizar(SDL_Texture *text)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 1000;
    src.h = 1000;

    SDL_Rect dest;
    dest.x = 500;
    dest.y = 500;
    dest.w = 32;
    dest.h = 32;

    SDL_RenderCopy(renderer, text, &src, &dest);
}

void RendererWindow::mostrar()
{
    SDL_RenderPresent(renderer);
}


