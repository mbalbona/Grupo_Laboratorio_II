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
                                SDL_WINDOWPOS_UNDEFINED,///Posicion de la ventana
                                SDL_WINDOWPOS_UNDEFINED,
                                400,                    ///Largo
                                200,                    ///Ancho
                                SDL_WINDOW_RESIZABLE    ///La ventana sera reescalable
                                );

    if(window == nullptr){
        cout<<"ERROR! NO SE INIICALIZO CORRECTAMENTE LA VENTANA!"<<endl;
        cout<<"Error: "<<SDL_GetError();
        system("pause");
        return false;
    }
    SDL_Delay(5000);
    SDL_DestroyWindow(window);                         ///Destruye ventana

    SDL_Quit();

    return true;
}

void Game::render()
{

}
