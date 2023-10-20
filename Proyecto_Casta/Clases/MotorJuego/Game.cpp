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


void Game::init()
{

    SDL_Init(SDL_INIT_EVERYTHING);                                          ///INICIAMOS SDL
    RendererWindow window("test", ancho_ventana, largo_ventana);

    SDL_Event event_handler;                                                ///DECLARAMOS MANAGER DE EVENTOS

    SDL_Texture *nivel_1 = window.cargar_textura("Graficos/nivel_1.png");   ///BUSCAMOS LA IMAGEN QUE SE CARGARA
    SDL_Texture *pj1 = window.cargar_textura("Graficos/Personajes/MILEI/milei.png");
    SDL_Texture *enemigo1 = window.cargar_textura("Graficos/Personajes/Pato/patof.png");


    vector<Entidad> entidades = {Entidad(100, 100, nivel_1),                ///DECLARAMOS VECTOR CON FUNCIONALIDADES DINAMICAS DE ENTIDADES
                                 Entidad(400, 400, pj1),                    ///UTILIZANDO LA LIBRERIA VECTOR DE C++
                                 Entidad(200, 200, enemigo1)};


    bool estaAndando = true;                                                ///BOOLEANO PARA DETERMINAR QUE ESTA TODO FUNCIONANDO HASTA ESE PUNTO


    ///WHILE PRINCIPAL ACA ADENTRO SE CARGAN TODAS LAS TEXTURAS Y ENTIDADES QUE USAREMOS PARA LOS PERSONAJES ENEMIGOS Y NIVELES

    while(estaAndando){                                                     ///LOOP O CICLO PRINCIPAL

        while(SDL_PollEvent(&event_handler)){

            if(event_handler.type == SDL_QUIT) estaAndando = false;         ///SI EL MANAGER DE EVENTOS DETECTA QUE SALE DEL PROGRAMA
                                                                            ///ESTE FINALIZARA
        }

        window.vaciar();

        for(Entidad &i : entidades){                                        ///DECLARAMOS BUCLE FOR BASADO EN RANGOS
            window.renderizar(i);                                           ///BUCLE FOR QUE SE UTILIZA PARA ITERAR SOBRE UNA SECUENCIA DE ELEMENTOS.
        }

        window.mostrar();


    }

    window.limpiar();
    SDL_Quit();
}


