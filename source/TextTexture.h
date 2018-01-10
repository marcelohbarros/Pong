#ifndef TEXTTEXTURE_H_INCLUDED
#define TEXTTEXTURE_H_INCLUDED
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class TextTexture
{
private:
    SDL_Texture *texture;
    std::string text;
    int width;
    int height;
public:
    TextTexture();
    ~TextTexture();
    void loadTexture(SDL_Renderer *renderer, TTF_Font *font, std::string text_, SDL_Color color = {255, 255, 255, 255});
    void free();
    void render(SDL_Renderer *renderer, int x = 0, int y = 0);
    int getWidth();
    int getHeight();
    std::string getText();
};

#endif //TEXTTEXTURE_H_INCLUDED
