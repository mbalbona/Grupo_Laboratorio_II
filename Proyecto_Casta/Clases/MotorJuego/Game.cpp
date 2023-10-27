#include <iostream>
#include <vector>
#include <SDL2/SDL_image.h>
#include "SDL.h"
#include "RendererWindow.h"
#include "Entidad.h"
#include "Game.h"

                                                                            ///#define es una directiva del preprocesador que permite definir constantes y macros.
#define ancho_ventana 1280                                                  ///Constante es un valor que no puede cambiar durante la ejecución del programa.
#define largo_ventana 720                                                   ///Macro es una sustitución de texto que se realiza antes de que el código sea compilado.

using namespace std;

Uint32 limit_frames(double target_fps, Uint32 ultimo_frame);

Game::Game()
{
    if(SDL_Init(SDL_INIT_EVERYTHING < 0))
       {
            cout << "ERROR AL INICIAR SDL2: " << SDL_GetError() << endl;                    ///INICIAMOS SDL
       }
}

Game::~Game()
{
    SDL_Quit();                                                                             ///CERRAMOS JUEGO
}

void Game::Run()
{

    RendererWindow window("test", ancho_ventana, largo_ventana);                            ///CREAMOS UNA VENTANA

    SDL_Event event_handler;                                                                ///DECLARAMOS MANAGER DE EVENTOS
    SDL_Texture *nivel_1 = window.cargar_textura("Graficos/nivel_1.png");                   ///BUSCAMOS LA IMAGEN QUE SE CARGARA
    SDL_Texture *pj1 = window.cargar_textura("Graficos/Personajes/MILEI/milei.png");
    SDL_Texture *enemigo1 = window.cargar_textura("Graficos/Personajes/Pato/patof.png");

    int x = 0;                                                                              ///DECLARAMOS VARIABLE PARA MOVER PERSONAJE EN EL EJE X
    int y = 0;                                                                              ///DECLARAMOS VARIABLE PARA MOVER PERSONAJE EN EL EJE Y

    vector<Entidad> entidades = {Entidad(Vector(100, 100), nivel_1),                        ///DECLARAMOS VECTOR CON FUNCIONALIDADES DINAMICAS DE ENTIDADES
                                 Entidad(Vector(400, 400), pj1),                            ///UTILIZANDO LA LIBRERIA VECTOR DE C++
                                 Entidad(Vector(200, 200), enemigo1)};

    bool estaAndando = true;
    Uint32 ultimo_frame = SDL_GetTicks();                                                  ///BOOLEANO PARA DETERMINAR QUE ESTA TODO FUNCIONANDO HASTA ESE PUNTO

    ///WHILE PRINCIPAL ACA ADENTRO SE CARGAN TODAS LAS TEXTURAS Y ENTIDADES QUE USAREMOS PARA LOS PERSONAJES ENEMIGOS Y NIVELES

    while(estaAndando){                                                 ///LOOP O CICLO PRINCIPAL
        while(SDL_PollEvent(&event_handler)){                           ///PROCESAMOS LOS EVENTOS
            switch(event_handler.type){
                case SDL_QUIT:                                          ///SI EL MANAGER DE EVENTOS DETECTA QUE SALE DEL PROGRAMA
                    return;                                             ///ESTE FINALIZARA
            }
        }

        for(Entidad &i : entidades){                                        ///DECLARAMOS CICLO FOR BASADO EN RANGOS
                                                                            ///CICLO FOR QUE SE UTILIZA PARA ITERAR SOBRE UNA SECUENCIA DE ELEMENTOS.
            window.renderizar(i);                                           ///DIBUJA LAS TEXTURAS
        }

        window.mostrar();                                                   ///MUESTRA LA TEXTURA CARGADA

        ultimo_frame = limit_frames(60, ultimo_frame);                      ///LIMITAMOS FRAMES
        //cout << ultimo_frame << endl;
    }

    window.limpiar();                                                       ///LIMPIAMOS LA MEMORIA USADA POR LAS TEXTURAS
}


Uint32 limit_frames(double target_fps, Uint32 ultimo_frame) {
  /// Obtenemos el tiempo actual
  Uint32 ahora = SDL_GetTicks();

  /// Calculamos el tiempo transcurrido desde el último frame
  Uint32 tiempo_transcurrido = ahora - ultimo_frame;

  /// Si el tiempo transcurrido es inferior al objetivo, esperamos
  if (tiempo_transcurrido < (1000 / target_fps)) {
    SDL_Delay((1000 / target_fps) - target_fps);
  }

  /// Actualizamos el tiempo del último frame
  ultimo_frame = ahora;

  return ultimo_frame;
}


