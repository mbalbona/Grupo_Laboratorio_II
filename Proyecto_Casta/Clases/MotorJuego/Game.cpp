#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"

using namespace std;


Game::Game()
{
    //ctor
}

bool Game::run()
{

    SDL_Init(SDL_INIT_EVERYTHING); ///INICIAMOS SDL

    SDL_Window *window;

    window = SDL_CreateWindow("Testing",               ///CREACION DE VENTANA
                                SDL_WINDOWPOS_CENTERED,///Posicion de la ventana en eje X
                                SDL_WINDOWPOS_CENTERED,///Posicion de la ventana en eje Y
                                400,                   ///Largo
                                200,                   ///Ancho
                                SDL_WINDOW_RESIZABLE   ///Comportamiento de la ventana
                                );

    if(window == nullptr){
        cout<<"ERROR! NO SE INIICALIZO CORRECTAMENTE LA VENTANA!"<<endl;
        cout<<"Error: "<<SDL_GetError();
        system("pause");
        return false;
    }

    SDL_Event event_handler;                            ///DECLARAMOS MANAGER DE EVENTOS
    bool estaAndando = true;                            ///BOOLEANO PARA DETERMINAR QUE ESTA TODO FUNCIONANDO HASTA ESE PUNTO

    while(estaAndando){                                 ///LOOP O CICLO PRINCIPAL

        while(SDL_PollEvent(&event_handler)){

            if(event_handler.type == SDL_QUIT){         ///SI EL MANAGER DE EVENTOS DETECTA QUE SALE DEL PROGRAMA
                estaAndando = false;                    ///ESTE FINALIZARA
                break;
            }

        }


    }


    SDL_DestroyWindow(window);                         ///Destruye ventana

    SDL_Quit();

    return true;
}

