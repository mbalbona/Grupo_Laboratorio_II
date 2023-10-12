#include <iostream>
#include <string>

class Personaje {

public:
    // Constructor
    Personaje(std::string nombre, int posX, int posY);

    // M�todo para mover al personaje
    void mover(int deltaX, int deltaY);
//Borrar anterior
void borrar();
    // M�todo para mostrar la informaci�n del personaje
    void mostrarInfo() ;

    private:
    std::string _nombre;
    int _posX;
    int _posY;

};

