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
#define fps 0.12

using namespace std;

void Game::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);                                                          ///INICIAMOS SDL
    RendererWindow window("test", ancho_ventana, largo_ventana);
    cout << window.getTasaDeRefresco() << endl;

    SDL_Event event_handler;                                                                ///DECLARAMOS MANAGER DE EVENTOS

    SDL_Texture *nivel_1 = window.cargar_textura("Graficos/nivel_1.png");                   ///BUSCAMOS LA IMAGEN QUE SE CARGARA
    SDL_Texture *pj1 = window.cargar_textura("Graficos/Personajes/MILEI/milei.png");
    SDL_Texture *enemigo1 = window.cargar_textura("Graficos/Personajes/Pato/patof.png");


    vector<Entidad> entidades = {Entidad(Vector(100, 100), nivel_1),                        ///DECLARAMOS VECTOR CON FUNCIONALIDADES DINAMICAS DE ENTIDADES
                                 Entidad(Vector(400, 400), pj1),                            ///UTILIZANDO LA LIBRERIA VECTOR DE C++
                                 Entidad(Vector(200, 200), enemigo1)};


    bool estaAndando = true;                                                                ///BOOLEANO PARA DETERMINAR QUE ESTA TODO FUNCIONANDO HASTA ESE PUNTO

    float acumulador = 0.0f;
    float tiempoActual = tiempoEnSegundos();
    int ticks_iniciales = SDL_GetTicks();




    ///WHILE PRINCIPAL ACA ADENTRO SE CARGAN TODAS LAS TEXTURAS Y ENTIDADES QUE USAREMOS PARA LOS PERSONAJES ENEMIGOS Y NIVELES

    while(estaAndando){                                                                     ///LOOP O CICLO PRINCIPAL
        int ticks_iniciales = SDL_GetTicks();

        float nuevoTiempo = tiempoEnSegundos();
        float tiempo_de_frame = nuevoTiempo - tiempoActual;

        tiempoActual = nuevoTiempo;
        acumulador += tiempo_de_frame;

        while(acumulador >= fps)
        {
            while(SDL_PollEvent(&event_handler)){

                if(event_handler.type == SDL_QUIT) estaAndando = false;     ///SI EL MANAGER DE EVENTOS DETECTA QUE SALE DEL PROGRAMA
                                                                            ///ESTE FINALIZARA
            }

            acumulador -= fps;
        }

        window.vaciar();                                                    ///VACIA LA VENTANA

        for(Entidad &i : entidades){                                        ///DECLARAMOS BUCLE FOR BASADO EN RANGOS
                                                                            ///BUCLE FOR QUE SE UTILIZA PARA ITERAR SOBRE UNA SECUENCIA DE ELEMENTOS.

            window.renderizar(i);                                           ///DIBUJA LAS TEXTURAS
        }


        int frameTicks = SDL_GetTicks() - ticks_iniciales;                  ///LIMITAMOS LOS FRAMES POR SEGUNDO PARA QUE NO CONSUMA LA TOTALIDAD
                                                                            ///DE RECURSOS DEL EQUIPO EN EL QUE ESTAMOS CORRIENDO EL JUEGO
                                                                            ///
        if(frameTicks < 1000 / window.getTasaDeRefresco())                  ///
        {                                                                   ///
            SDL_Delay(1000 / window.getTasaDeRefresco() - frameTicks);      ///
        }                                                                   ///
                                                                            ///
        cout << frameTicks << endl;                                         ///



        window.mostrar();                                                   ///MUESTRA LA TEXTURA CARGADA


    }




    window.limpiar();                                                       ///LIMPIAMOS LA MEMORIA USADA POR LAS TEXTURAS
    SDL_Quit();                                                             ///CERRAMOS JUEGO
}


