#include <iostream>
#include "SDL.h"
#include <SDL2/SDL_image.h>
#include "Window.h"
#include "Game.h"
#include "Texture.h"

#define ancho_ventana 1280                              ///Constante es un valor que no puede cambiar durante la ejecución del programa.
#define largo_ventana 720                               ///Macro es una sustitución de texto que se realiza antes de que el código sea compilado.
#define fps 60                                          ///Definimos los fps en los que queremos que corra el programa

using namespace std;



Game::Game()
{
    _isRunning = true;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cout << "HUBO UN ERROR: error " << SDL_GetError() << endl;
    }
}

void Game::HandleEvent(SDL_Event event)
{
    switch(event.type){
                case SDL_QUIT:
                    _isRunning = false;

                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_w){
                        cout << "W PRESIONADA" << endl;
                    }
                    if(event.key.keysym.sym == SDLK_a){
                        cout << "A PRESIONADA" << endl;
                    }
                    if(event.key.keysym.sym == SDLK_s){
                        cout << "S PRESIONADA" << endl;
                    }
                    if(event.key.keysym.sym == SDLK_d){
                        cout << "D PRESIONADA" << endl;
                    }
                    if(event.key.keysym.sym == SDLK_SPACE){
                        cout << "ESPACIO PRESIONADO" << endl;
                    }
                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        _isRunning = false;
                    }

            }
}

void Game::limitFrames(int frames, int last)
{
    int current_frame = SDL_GetTicks();
    int timer = current_frame - last;
    if(timer < (100 / fps) )
    {
        SDL_Delay(( 1000/fps ) - timer);
    }

    last = current_frame;

    cout << last << endl;
}

void Game::Run()
{
    SDL_Window *window = SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 400, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Texture _pjPrincipal("./Graficos/Personajes/Mileipj/mileparadosprite.png", renderer, 29, 160, 400, 400);

    int last_frame = SDL_GetTicks();

    int frame_index = 0;

    while(_isRunning){

        limitFrames(fps, last_frame);

        SDL_Event event;

        while(SDL_PollEvent(&event)){
            HandleEvent(event);
        }

        _pjPrincipal.Render(renderer);
        _pjPrincipal.Show(renderer);
    }

    SDL_DestroyWindow(window);
}

