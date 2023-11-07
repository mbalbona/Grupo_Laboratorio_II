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
    _isRunning = true;

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
                    isRunning = false;                                  ///ESTE FINALIZARA
            }
        }
}


void Game::Run()
{

    _window = new RendererWindow("Test", largo_ventana, ancho_ventana);                         ///CREAMOS UNA VENTANA

    _backgroundTexture = new Texture("Graficos/nivel_1.png");                                   ///BUSCAMOS LA IMAGEN QUE SE CARGARA

    auto ultimo_frame = std::chrono::system_clock::now();


    ///WHILE PRINCIPAL ACA ADENTRO SE CARGAN TODAS LAS TEXTURAS Y ENTIDADES QUE USAREMOS PARA LOS PERSONAJES ENEMIGOS Y NIVELES

    while(isRunning){                                                       ///LOOP O CICLO PRINCIPAL

        auto frame_actual = std::chrono::system_clock::now();

        std::chrono::duration<double> segundos_transcurridos = frame_actual - ultimo_frame;

        handleEvents();

        cout << segundos_transcurridos << endl;

        window.Update(segundos_transcurridos.count(), entidades[0]);        ///ACTUALIZAMOS FRAMES

        Render(_window.getRenderer());

        ultimo_frame = frame_actual;
    }

    ///FIN CICLO JUEGO

    window.Release();                                                       ///LIMPIAMOS LA MEMORIA USADA POR LAS TEXTURAS
}

void Game::Render(RendererWindow &renderer)
{
    SDL_RenderClear(renderer)
    _backgroundTexture->render();
    SDL_RenderCopy(renderer, _texture, &_srcRect, destRect);
}


