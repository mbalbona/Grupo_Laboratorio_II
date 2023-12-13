#include <ctime>
#include <iostream>
#include "personaje.h"
#include "Texture.h"



void Personaje::mover(int deltaX, int deltaY) {
    _posX += deltaX;
    _posY += deltaY;
}


void Personaje::mostrarInfo() {
    std::cout << "Nombre: " << _nombre << ", Posición: (" << _posX << ", " << _posY << ")\n";
}


