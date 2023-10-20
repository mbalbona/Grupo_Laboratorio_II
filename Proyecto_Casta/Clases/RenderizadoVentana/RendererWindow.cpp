#include <iostream>
#include "SDL.h"
#include <SDL2/SDL_image.h>
#include "RendererWindow.h"
#include "Entidad.h"


using namespace std;


RendererWindow::RendererWindow(const char *titulo, int largo, int ancho)
: window(nullptr), renderer(nullptr)                        ///LISTA DE INICIALIZACION DE MIEMBROS:
                                                            ///PERMITE INICIALIZAR LOS MIEMBROS DE UNA CLASE EN EL CONSTRUCTOR DE LA CLASE.
                                                            ///LA LISTA DE INICIALIZACION DE MIEMBROS SE ESPECIFICA DESPUES DE LA LISTA DE PARAMETROS DEL CONSTRUCTOR,
                                                            ///Y ESTA COMPUESTA POR UNA LISTA DE INICIALIZADORES PARA LOS MIEMBROS DE LA CLASE, SEPARADOS POR COMAS.
{



    window = SDL_CreateWindow(titulo,                       ///CREACION DE VENTANA
                              SDL_WINDOWPOS_UNDEFINED,      ///Posicion de la ventana en eje X
                              SDL_WINDOWPOS_UNDEFINED,      ///Posicion de la ventana en eje Y
                              largo,                        ///Largo
                              ancho,                        ///Ancho
                              SDL_WINDOW_SHOWN);            ///Comportamiento de la ventana

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








int RendererWindow::getTasaDeRefresco()
{
  int mostrarIndex = SDL_GetWindowDisplayIndex(window);

  SDL_DisplayMode modo;

  SDL_GetDisplayMode(mostrarIndex, 0, &modo);

  // Verifica si la tasa de refresco es 0

  if (modo.refresh_rate == 0) {
    // Si es 0, devuelve -1
    return -1;
  }

  // Devuelve la tasa de refresco

  return modo.refresh_rate;
}




void RendererWindow::limpiar()
{
    SDL_DestroyWindow(window);
}




void RendererWindow::vaciar()
{
    SDL_RenderClear(renderer);
}




void RendererWindow::renderizar(Entidad &entid)
{
    SDL_Rect src;
    src.x = entid.getFrameActual().x;
    src.y = entid.getFrameActual().y;
    src.w = entid.getFrameActual().w;
    src.h = entid.getFrameActual().h;

    SDL_Rect dest;
    dest.x = entid.getPos().getX();
    dest.y = entid.getPos().getY();
    dest.w = entid.getFrameActual().w;
    dest.h = entid.getFrameActual().h;

    SDL_RenderCopy(renderer, entid.getTextura(), &src, &dest);
}





void RendererWindow::mostrar()
{
    SDL_RenderPresent(renderer);
}




