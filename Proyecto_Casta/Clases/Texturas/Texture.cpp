#include <iostream>
#include <string>
#include <SDL2/SDL_image.h>
#include "SDL.h"
#include "Texture.h"

using namespace std;

///CONSTRUCTOR
Texture::Texture(std::string path, SDL_Renderer *renderer, int x, int y, int src_w, int src_h, int dest_w, int dest_h):
_texture(nullptr), _frameIndex(0)
{
    SDL_Surface *surface = IMG_Load(path.c_str());
    _texture = SDL_CreateTextureFromSurface(renderer, surface);

    if(_texture == nullptr){
        cout << "ERROR EN LA CARGA DE IMAGEN!";
        system("pause");
    }


    _srcRect.x = 0;
    _srcRect.y = 0;
    _srcRect.w = src_w;
    _srcRect.h = src_h;

    _destRect.x = x;
    _destRect.y = y;
    _destRect.w = dest_w;
    _destRect.h = dest_h;

    SDL_FreeSurface(surface);

}


Texture::~Texture()
{
    SDL_DestroyTexture(_texture);
}




void Texture::Update(SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);
    _frameIndex += 1;
    _srcRect.x = (_frameIndex % 5) * 32;

}

void Texture::Render(SDL_Renderer* renderer) const
{

    SDL_RenderCopy(renderer, _texture, &_srcRect , &_destRect);

    SDL_RenderPresent(renderer);
}


