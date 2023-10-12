#include <ctime>
#include <iostream>
#include "personaje.h"



    Personaje::Personaje(std::string nombre, int posX, int posY){
    _nombre=nombre;
    _posX=posX;
    _posY=posY;


    }


    void Personaje::mover(int deltaX, int deltaY) {
        _posX += deltaX;
        _posY += deltaY;
    }


    void Personaje::mostrarInfo() {
        std::cout << "Nombre: " << _nombre << ", Posición: (" << _posX << ", " << _posY << ")\n";
    }


