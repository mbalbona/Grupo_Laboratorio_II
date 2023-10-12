#include <iostream>
#include "SDL.h"
#include <SDL2/SDL_image.h>
#include "RendererWindow.h"
#include "Game.h"

#define ancho_ventana 1280                              ///Constante es un valor que no puede cambiar durante la ejecución del programa.
#define largo_ventana 720                               ///Macro es una sustitución de texto que se realiza antes de que el código sea compilado.


using namespace std;


void Game::init()
{

    SDL_Init(SDL_INIT_EVERYTHING);                                          ///INICIAMOS SDL
    RendererWindow window("test", ancho_ventana, largo_ventana);

    SDL_Event event_handler;                                                ///DECLARAMOS MANAGER DE EVENTOS

    SDL_Texture *nivel_1 = window.cargar_textura("Graficos/nivel_1.png");   ///BUSCAMOS LA IMAGEN QUE SE CARGARA

    bool estaAndando = true;                                                ///BOOLEANO PARA DETERMINAR QUE ESTA TODO FUNCIONANDO HASTA ESE PUNTO

    while(estaAndando){                                                     ///LOOP O CICLO PRINCIPAL

        while(SDL_PollEvent(&event_handler)){

            if(event_handler.type == SDL_QUIT) estaAndando = false;                             ///SI EL MANAGER DE EVENTOS DETECTA QUE SALE DEL PROGRAMA
                                                                                                ///ESTE FINALIZARA
        }
        window.vaciar();
      window.renderizar(nivel_1);
        window.mostrar();


    }
    SDL_Texture *pj1=window.cargar_textura("Graficos/Personajes/MILEI/milei.png" );
      bool estaAndandopj1 = true;                                                ///BOOLEANO PARA DETERMINAR QUE ESTA TODO FUNCIONANDO HASTA ESE PUNTO

    while(estaAndandopj1){                                                     ///LOOP O CICLO PRINCIPAL

        while(SDL_PollEvent(&event_handler)){

            if(event_handler.type == SDL_QUIT) estaAndandopj1 = false;                             ///SI EL MANAGER DE EVENTOS DETECTA QUE SALE DEL PROGRAMA
                                                                                                ///ESTE FINALIZARA
        }
        window.vaciar();
        window.renderizar(pj1);
        window.mostrar();


}
    window.limpiar();
    SDL_Quit();
}


