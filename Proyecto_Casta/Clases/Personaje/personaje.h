#include <iostream>
#include <string>
#include "SDL.h"
#include <SDL2/SDL_image.h>
class Personaje {

public:
    // Constructor
    Personaje(std::string nombre, int posX, int posY);
GameObject(const char* texturacargar,SDL_Renderer* ren);


    // Método para mover al personaje
    void mover(int deltaX, int deltaY);
//Borrar anterior
void borrar();
    // Método para mostrar la información del personaje
    void mostrarInfo() ;

    private:
    std::string _nombre;
    int _posX;
    int _posY;
SDL_Texture* objtexture;
SDL_Rect srcRect,destRect;
SDL_Renderer* renderer;
};

