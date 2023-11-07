#include <iostream>
#include "SDL.h"
#include <SDL2/SDL_image.h>
#include "RendererWindow.h"
#include "Entidad.h"


using namespace std;


RendererWindow::RendererWindow(const char *titulo, int largo, int ancho)
: window(nullptr)                        ///LISTA DE INICIALIZACION DE MIEMBROS:
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

}




int RendererWindow::getRefreshRate()
{
  int displayIndex = SDL_GetWindowDisplayIndex(window);

  SDL_DisplayMode modo;

  SDL_GetDisplayMode(displayIndex, 0, &modo);

  // Verifica si la tasa de refresco es 0

  if (modo.refresh_rate == 0) {
    // Si es 0, devuelve -1
    return -1;
  }

  // Devuelve la tasa de refresco

  return modo.refresh_rate;
}


void RendererWindow::Update(double elapsed_seconds, Entidad &entid)
{
    frame_index = int( ( (SDL_GetTicks() / 100) % 10) );

    entid.getPos().setX(frame_index * 587);

}



void RendererWindow::Release()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}



