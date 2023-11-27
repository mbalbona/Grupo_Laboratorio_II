#ifndef TEXTURE_H
#define TEXTURE_H

using namespace std;

class Texture
{
    public:
        ///Constructor y Destructor
        Texture(std::string path, SDL_Renderer *renderer, int x, int y, int src_w, int src_h, int dest_w, int dest_h);
        ~Texture();

        ///Metodos
        void Update(SDL_Renderer *);
        void Render(SDL_Renderer *) const;

        ///GETTERS
        int getDestRect_X(){return _destRect.x;}
        int getDestRect_Y(){return _destRect.y;}

    private:
        SDL_Rect _srcRect;
        SDL_Rect _destRect;
        SDL_Texture *_texture;
        int _frameIndex;
};

#endif // TEXTURE_H

