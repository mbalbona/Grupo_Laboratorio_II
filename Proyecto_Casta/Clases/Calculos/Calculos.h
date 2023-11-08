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
        void setX(float pos_x){x = pos_x;}
        void setY(float pos_y){y = pos_y;}

    private:
        float x, y;
};


