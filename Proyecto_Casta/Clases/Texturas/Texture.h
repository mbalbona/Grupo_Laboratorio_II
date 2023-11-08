#ifndef TEXTURE_H
#define TEXTURE_H

using namespace std;

class Texture
{
    public:
        Texture(std::string path, SDL_Renderer *renderer);

        void Init();
        void render(const SDL_Rect *destRect) const;
    private:
        std::string _path;
        SDL_Renderer *_renderer;
        SDL_Rect _srcRect;
        SDL_Texture *_texture;
};

#endif // TEXTURE_H
