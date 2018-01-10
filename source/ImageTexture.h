#ifndef IMAGETEXTURE_H_INCLUDED
#define IMAGETEXTURE_H_INCLUDED
#include <SDL.h>
#include <string>

class ImageTexture
{
private:
    SDL_Texture *texture;
    int width;
    int height;
public:
    ImageTexture();
    ~ImageTexture();
    void loadTexture(SDL_Renderer *renderer, std::string path);
    void free();
    void render(SDL_Renderer *renderer, int x = 0, int y = 0);
    int getWidth();
    int getHeight();
};

#endif //IMAGETEXTURE_H_INCLUDED
