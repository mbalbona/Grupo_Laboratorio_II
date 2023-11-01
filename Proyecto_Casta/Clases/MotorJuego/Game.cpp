#include <iostream>
#include <vector>
#include <chrono>
#include <SDL2/SDL_image.h>
#include "SDL.h"
#include "RendererWindow.h"
#include "Entidad.h"
#include "Game.h"

                                                                            ///#define es una directiva del preprocesador que permite definir constantes y macros.
#define ancho_ventana 1280                                                  ///Constante es un valor que no puede cambiar durante la ejecución del programa.
#define largo_ventana 720                                                   ///Macro es una sustitución de texto que se realiza antes de que el código sea compilado.

using namespace std;

Game::Game()
{
    isRunning = true;

    if(SDL_Init(SDL_INIT_EVERYTHING < 0))
       {
            cout << "ERROR AL INICIAR SDL2: " << SDL_GetError() << endl;                    ///INICIAMOS SDL
       }
}

void Game::handleEvents()
{
    SDL_Event event_handler;                                            ///DECLARAMOS MANAGER DE EVENTOS
    if(SDL_PollEvent(&event_handler)){                                  ///PROCESAMOS LOS EVENTOS
            switch(event_handler.type){
                case SDL_QUIT:                                          ///SI EL MANAGER DE EVENTOS DETECTA QUE SALE DEL PROGRAMA
                    isRunning = false;                                ///ESTE FINALIZARA
            }
        }
}


void Game::Run()
{

    RendererWindow window("test", ancho_ventana, largo_ventana);                            ///CREAMOS UNA VENTANA

    SDL_Texture *nivel_1 = window.loadTexture("Graficos/nivel_1.png");                   ///BUSCAMOS LA IMAGEN QUE SE CARGARA
    SDL_Texture *pj1 = window.loadTexture("Graficos/Personajes/MILEI/milei.png");
    SDL_Texture *enemigo1 = window.loadTexture("Graficos/Personajes/Pato/patof.png");

    vector<Entidad> entidades = {Entidad(Vector(100, 100), nivel_1),                        ///DECLARAMOS VECTOR CON FUNCIONALIDADES DINAMICAS DE ENTIDADES
                                 Entidad(Vector(400, 400), pj1),                            ///UTILIZANDO LA LIBRERIA VECTOR DE C++
                                 Entidad(Vector(200, 200), enemigo1)};

    auto ultimo_frame = SDL_GetTicks();


    ///WHILE PRINCIPAL ACA ADENTRO SE CARGAN TODAS LAS TEXTURAS Y ENTIDADES QUE USAREMOS PARA LOS PERSONAJES ENEMIGOS Y NIVELES

    while(isRunning){                                                     ///LOOP O CICLO PRINCIPAL

        auto frame_actual = SDL_GetTicks();
        double segundos_transcurridos = frame_actual - ultimo_frame;

        handleEvents();

        window.update(segundos_transcurridos, entidades[0]);                ///ACTUALIZAMOS FRAMES

        for(Entidad &i : entidades){                                        ///DECLARAMOS CICLO FOR BASADO EN RANGOS
                                                                            ///CICLO FOR QUE SE UTILIZA PARA ITERAR SOBRE UNA SECUENCIA DE ELEMENTOS.
            window.render(i);                                                ///DIBUJA LAS TEXTURAS
        }

    }

    ///FIN CICLO JUEGO

    window.release();                                                       ///LIMPIAMOS LA MEMORIA USADA POR LAS TEXTURAS
}



