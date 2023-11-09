#ifndef TEXTURE_H
#define TEXTURE_H

using namespace std;

class Texture
{
    public:
        ///Constructor y Destructor
        Texture(std::string path, SDL_Renderer *renderer);
        ~Texture();

        ///Setters
        void setPosition(int x, int y);
        void setSize(int w, int h);
        ///Setters
        int getPosX(){return _rect.x;}
        int getPosY(){return _rect.y;}

        ///Metodos
        void Update(SDL_Renderer *&);
        void Render(SDL_Renderer *&) const;
    private:
        SDL_Rect _rect;
        SDL_Texture *_texture;
};

#endif // TEXTURE_H
