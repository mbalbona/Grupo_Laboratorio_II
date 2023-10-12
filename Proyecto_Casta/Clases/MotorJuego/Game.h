#pragma once

using namespace std;


/**
CLASE GAME

CLASE CONTENEDORA DEL MOTOR DE JUEGO PRINCIPAL Y DONDE ESTA UBICADO EL LOOP PRINCIPAL QUE RENDERIZARA LAS VENTANAS SDL
*/
class Game
{
public:

    void init();

private:
    Uint32 reloj_fps;
};

