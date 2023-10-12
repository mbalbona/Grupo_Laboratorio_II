#include <iostream>
#include <string>

class Personaje {

public:
    // Constructor
    Personaje(std::string nombre, int posX, int posY);

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

};

