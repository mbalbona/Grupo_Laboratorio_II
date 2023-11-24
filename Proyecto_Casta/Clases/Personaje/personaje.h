#include <iostream>
#include <string>
#include "SDL.h"
#include <SDL2/SDL_image.h>
#include "Texture.h"

class Personaje : public Texture {

public:
    //GameObject(const char* texturacargar,SDL_Renderer* ren);


    // M�todo para mover al personaje
    void mover(int deltaX, int deltaY);
    //Borrar anterior
    void borrar();
    // M�todo para mostrar la informaci�n del personaje
    void mostrarInfo() ;

    private:
    std::string _nombre;

};

