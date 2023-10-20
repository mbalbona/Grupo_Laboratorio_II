#pragma once

#include <iostream>



class Vector
{
    public:
        Vector();
        Vector(float, float);
        void mostrar();

        float getX(){return x;}
        float getY(){return y;}
    private:
        float x, y;
};

float tiempoEnSegundos();

