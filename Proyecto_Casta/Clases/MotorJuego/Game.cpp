#include <iostream>
#include "SDL.h"
#include <SDL2/SDL_image.h>
#include "RendererWindow.h"
#include "Game.h"

#define ancho_ventana 1280                              ///Constante es un valor que no puede cambiar durante la ejecuci�n del programa.
#define largo_ventana 720                               ///Macro es una sustituci�n de texto que se realiza antes de que el c�digo sea compilado.


using namespace std;


void Game::init()
{

    SDL_Init(SDL_INIT_EVERYTHING);                                          ///INICIAMOS SDL
    RendererWindow window("test", ancho_ventana, largo_ventana);

    SDL_Event event_handler;                                                ///DECLARAMOS MANAGER DE EVENTOS
    bool estaAndando = true;                                                ///BOOLEANO PARA DETERMINAR QUE ESTA TODO FUNCIONANDO HASTA ESE PUNTO

    while(estaAndando){                                                     ///LOOP O CICLO PRINCIPAL

        while(SDL_PollEvent(&event_handler)){

            if(event_handler.type == SDL_QUIT) estaAndando = false;                             ///SI EL MANAGER DE EVENTOS DETECTA QUE SALE DEL PROGRAMA
                                                                                                ///ESTE FINALIZARA
        }


    }

    window.limpiar();
    SDL_Quit();
}


