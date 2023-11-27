#include <iostream>
#include <string>
#include <SDL2/SDL_image.h>
#include "SDL.h"
#include "Texture.h"

using namespace std;

///CONSTRUCTOR
Texture::Texture(std::string path, SDL_Renderer *renderer, int x, int y, int w, int h):
_texture(nullptr)
{
    SDL_Surface *surface = IMG_Load(path.c_str());
    _texture = SDL_CreateTextureFromSurface(renderer, surface);

    _srcRect.x = 0;
    _srcRect.y = 0;
    _srcRect.w = 29;
    _srcRect.h = 40;

    _destRect.x = 0;
    _destRect.y = 0;
    _destRect.w = 160;
    _destRect.h = 160;

    SDL_FreeSurface(surface);
}


Texture::~Texture()
{
    SDL_DestroyTexture(_texture);
}




void Texture::Update(SDL_Renderer* renderer)
{
}

void Texture::Render(SDL_Renderer* renderer) const
{
    SDL_RenderCopy(renderer, _texture, &_srcRect , &_destRect);
}

void Texture::Show(SDL_Renderer* renderer)
{
    SDL_RenderPresent(renderer);
}

