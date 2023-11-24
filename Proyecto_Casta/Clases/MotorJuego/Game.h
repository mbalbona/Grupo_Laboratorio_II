#pragma once

using namespace std;

class Texture;

/**
CLASE GAME

CLASE CONTENEDORA DEL MOTOR DE JUEGO PRINCIPAL Y DONDE ESTA UBICADO EL LOOP PRINCIPAL QUE RENDERIZARA LAS VENTANAS SDL
*/
class Game
{
public:
    Game();

    void HandleEvent(SDL_Event);
    void limitFrames(int, int);
    void Run();


private:
    bool _isRunning;   ///BOOLEANO PARA DETERMINAR QUE ESTA TODO FUNCIONANDO HASTA ESE PUNTO
    SDL_Renderer *_renderer;
};

