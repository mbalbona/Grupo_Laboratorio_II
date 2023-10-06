#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"

#define fps 120                                        ///#define es una directiva del preprocesador que permite definir constantes y macros.
#define ancho_ventana 600                              ///Constante es un valor que no puede cambiar durante la ejecución del programa.
#define largo_ventana 800                              ///Macro es una sustitución de texto que se realiza antes de que el código sea compilado.


using namespace std;


Game::Game()
{
    //ctor
}

void Game::limitar_fps(Uint32 reloj_fps){

    if( (1000 / fps) > SDL_GetTicks() - reloj_fps ){            /// Si el tiempo transcurrido desde el último frame es menor que el tiempo de frame,
        SDL_Delay( 1000 / fps - ( SDL_GetTicks() - reloj_fps) );/// espera hasta que pase el tiempo suficiente.
    }

    cout<< reloj_fps << endl;
}


bool Game::run()
{

    SDL_Init(SDL_INIT_EVERYTHING);                     ///INICIAMOS SDL

    SDL_Window *window;

    window = SDL_CreateWindow("Testing",               ///CREACION DE VENTANA
                                SDL_WINDOWPOS_CENTERED,///Posicion de la ventana en eje X
                                SDL_WINDOWPOS_CENTERED,///Posicion de la ventana en eje Y
                                largo_ventana,         ///Largo
                                ancho_ventana,         ///Ancho
                                SDL_WINDOW_RESIZABLE   ///Comportamiento de la ventana
                                );

    if(window == nullptr){
        cout<<"ERROR! NO SE INIICALIZO CORRECTAMENTE LA VENTANA!"<<endl;
        cout<<"Error: "<<SDL_GetError();
        system("pause");
        return false;
    }



    int x, y ,w, h;                                                         ///X = EJE X
                                                                            ///Y = EJE Y
                                                                            ///W = WIDHT (LARGO)
                                                                            ///H = HEIGHT (ANCHO)



    SDL_Event event_handler;                                                ///DECLARAMOS MANAGER DE EVENTOS
    bool estaAndando = true;                                                ///BOOLEANO PARA DETERMINAR QUE ESTA TODO FUNCIONANDO HASTA ESE PUNTO

    Uint32 reloj_fps;                                                       ///VARIABLE ALMACENADORA DE LOS FRAMES POR SEGUNDO

    while(estaAndando){                                                     ///LOOP O CICLO PRINCIPAL

        reloj_fps = SDL_GetTicks();

        while(SDL_PollEvent(&event_handler)){

            if(event_handler.type == SDL_QUIT){                             ///SI EL MANAGER DE EVENTOS DETECTA QUE SALE DEL PROGRAMA
                estaAndando = false;                                        ///ESTE FINALIZARA
                break;
            }
        }

        limitar_fps(reloj_fps);                                             ///LIMITA EL RELOJ DE FPS

        SDL_UpdateWindowSurface(window);                                    ///ACTUALIZA LA PANTALLA MIENTRAS ESTA CORRIENDO EL JUEGO

        ///SDL_GetWindowPosition(window, &x, &y);                           CAPTURA LA POSICION DE LA VENTANA EN LA PANTALLA

        ///cout<< x <<" | "<< y <<endl;



    }


    SDL_DestroyWindow(window);                         ///Destruye ventana

    SDL_Quit();

    return true;
}

