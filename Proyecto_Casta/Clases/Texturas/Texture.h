#ifndef TEXTURE_H
#define TEXTURE_H

using namespace std;

class Texture
{
    public:
        ///Constructor y Destructor
        Texture(std::string path, SDL_Renderer *renderer, int x, int y, int w, int h);
        ~Texture();

        ///Metodos
        void Update(SDL_Renderer *);
        void Render(SDL_Renderer *) const;
        void Show(SDL_Renderer *);
    private:
        SDL_Rect _srcRect;
        SDL_Rect _destRect;
        SDL_Texture *_texture;
};

#endif // TEXTURE_H
