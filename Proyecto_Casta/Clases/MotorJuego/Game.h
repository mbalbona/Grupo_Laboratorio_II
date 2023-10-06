#pragma once

using namespace std;

class Game
{
    public:

        Game();

        void limitar_fps(Uint32);
        void init();

    private:
        Uint32 reloj_fps;
};

