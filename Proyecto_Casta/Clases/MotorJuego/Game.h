#pragma once

using namespace std;

class Texture;
class RendererWindow;

/**
CLASE GAME

CLASE CONTENEDORA DEL MOTOR DE JUEGO PRINCIPAL Y DONDE ESTA UBICADO EL LOOP PRINCIPAL QUE RENDERIZARA LAS VENTANAS SDL
*/
class Game
{
public:
    Game();

    void handleEvents();
    void Render(RendererWindow &_renderer);
    void Run();


private:
    bool _isRunning;   ///BOOLEANO PARA DETERMINAR QUE ESTA TODO FUNCIONANDO HASTA ESE PUNTO
    Texture *_backgroundTexture;
    RendererWindow *_window;
};

