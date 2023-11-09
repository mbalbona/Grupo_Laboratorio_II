#include <iostream>
#include <string>
#include <SDL2/SDL_image.h>
#include "SDL.h"
#include "Texture.h"

using namespace std;

///CONSTRUCTOR
Texture::Texture(std::string path, SDL_Renderer *renderer):
_texture(nullptr)
{
    SDL_Surface *surface = IMG_Load(path.c_str());
    _texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}


Texture::~Texture()
{
    SDL_DestroyTexture(_texture);
}

void Texture::setPosition(int x, int y)
{
    _rect.x = x;
    _rect.y = y;
}

void Texture::setSize(int w, int h)
{
    _rect.w = w;
    _rect.h = h;
}


void Texture::Update(SDL_Renderer*& renderer)
{
}

void Texture::Render(SDL_Renderer*& renderer) const
{
    SDL_RenderCopy(renderer, _texture, nullptr , &_rect);
}
