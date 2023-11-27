#include <iostream>
#include <string>
#include "SDL.h"
#include <SDL2/SDL_image.h>
#include "Texture.h"

class Personaje : public Texture {

public:
    //GameObject(const char* texturacargar,SDL_Renderer* ren);


    // Método para mover al personaje
    void mover(int deltaX, int deltaY);
    //Borrar anterior
    void borrar();
    // Método para mostrar la información del personaje
    void mostrarInfo() ;

    private:
    std::string _nombre;

};

