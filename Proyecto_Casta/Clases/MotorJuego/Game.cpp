#include <iostream>
#include "SDL.h"
#include <SDL2/SDL_image.h>
#include "Window.h"
#include "Game.h"
#include "Texture.h"

#define ancho_ventana 1280                              ///Constante es un valor que no puede cambiar durante la ejecución del programa.
#define largo_ventana 720                               ///Macro es una sustitución de texto que se realiza antes de que el código sea compilado.
#define fps 20                                          ///Definimos los fps en los que queremos que corra el programa

using namespace std;



Game::Game()
{
    _isRunning = true;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cout << "HUBO UN ERROR: error " << SDL_GetError() << endl;
    }
}

void Game::HandleEvent(SDL_Event event) {
    switch(event.type) {
        case SDL_QUIT:
            _isRunning = false;
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_SPACE) {
                cout << "ESPACIO PRESIONADO" << endl;
            } else if(event.key.keysym.sym == SDLK_ESCAPE) {
                _isRunning = false;
            } else {
                HandlePlayerMovement(event);
            }
            break;
    }
}
void Game::HandlePlayerMovement(SDL_Event event) {
    const int playerSpeed = 5; // Ajusta la velocidad según sea necesario

    switch(event.key.keysym.sym) {
        case SDLK_w:
            _playerY -= playerSpeed; // Mover hacia arriba
            break;
        case SDLK_a:
            _playerX -= playerSpeed; // Mover hacia la izquierda
            break;
        case SDLK_s:
            _playerY += playerSpeed; // Mover hacia abajo
            break;
        case SDLK_d:
            _playerX += playerSpeed; // Mover hacia la derecha
            break;
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

    SDL_Renderer *renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

    Texture _nivel1("./Graficos/nivel_1.png", renderer, 0, 0, 254, 240, 800, 400);

int last_frame = SDL_GetTicks();

    while(_isRunning){
 Texture _pjPrincipal("./Graficos/Personajes/Mileipj/mileparadosprite.png", renderer, 100, 100, 32, 34, 50, 50);

    while(_isRunning) {
        limitFrames(fps, last_frame);

        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            HandleEvent(event);
        }

        _nivel1.Render(renderer);

        // Actualiza la posición antes de renderizar
        _pjPrincipal.SetPosition(_playerX, _playerY);
        _pjPrincipal.Render(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
}


}
