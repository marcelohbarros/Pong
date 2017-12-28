#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED
#include <SDL.h>
#include <string>

class Texture
{
private:
    SDL_Texture *texture;
    int width;
    int height;
public:
    Texture();
    ~Texture();
    void loadTexture(SDL_Renderer *renderer, std::string path);
    void free();
    void render(SDL_Renderer *renderer, int x = 0, int y = 0);
    int getWidth();
    int getHeight();
};

#endif //TEXTURE_H_INCLUDED
