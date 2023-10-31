#pragma once

using namespace std;


/**
CLASE GAME

CLASE CONTENEDORA DEL MOTOR DE JUEGO PRINCIPAL Y DONDE ESTA UBICADO EL LOOP PRINCIPAL QUE RENDERIZARA LAS VENTANAS SDL
*/
class Game
{
public:
    Game();
    ~Game();

    void handleEvents();
    void render(RendererWindow window, vector<Entidad> entidades);
    void Run();


private:
    bool estaAndando;
};

