#include <iostream>
#include "SDL.h"
#include <SDL2/SDL_image.h>
#include <vector>

using namespace std;

#include "Entidad.h"
#include "RendererWindow.h"
#include "Game.h"


/**
Enlace de documentacion de SDL2 https://wiki.libsdl.org/SDL2/APIByCategory
en este enlace se encuentran todas las formas de uso de SDL, funciones, archivos.h y sus contenidos,
formas de uso, syntaxis, etc.

Consultar en caso de necesitar una ayuda extra ademas de videos explicativos,
altamente recomendado abrirlo mientras se miran dichos videos y durante la redaccion
del codigo fuente del actual programa.
*/
int main(int argc, char* argv[])
{
    Game test;

    test.Run();


    return EXIT_SUCCESS;
}




