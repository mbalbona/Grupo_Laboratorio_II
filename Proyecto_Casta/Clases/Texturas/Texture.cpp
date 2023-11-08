#include <iostream>
#include <vector>
#include <chrono>
#include <SDL2/SDL_image.h>
#include "SDL.h"
#include "Texture.h"

using namespace std;

Texture::Texture(std::string path, SDL_Renderer *renderer):
_path(path), _renderer(renderer), _texture(nullptr)
{
}

void Texture::Init()
{
    SDL_Surface *surface = IMG_Load(_path.c_str());
    _texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_QueryTexture(_texture, nullptr, nullptr, &_srcRect.w, &_srcRect.h);
    SDL_FreeSurface(surface);
}

void Texture::render(const SDL_Rect* destRect) const
{
    assert(_texture != nullptr && "No se inicializo correctamente la textura!");
    SDL_RenderCopy(_renderer, _texture, &_srcRect, destRect);
}
