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

    void handleEvents();
    void Run();


private:
    bool isRunning;   ///BOOLEANO PARA DETERMINAR QUE ESTA TODO FUNCIONANDO HASTA ESE PUNTO
};

