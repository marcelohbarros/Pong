#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Texture.h"
#include "config.h"

Texture::Texture()
{
    texture = NULL;
    width = 0;
    height = 0;
}

Texture::~Texture()
{
    free();
}

void Texture::loadTexture(SDL_Renderer *renderer, std::string path)
{
    free();
    SDL_Surface *surface = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    width = surface->w;
    height = surface->h;
    SDL_FreeSurface(surface);
    return;
}

void Texture::free()
{
    if(texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
        width = 0;
        height = 0;
    }
    return;
}

void Texture::render(SDL_Renderer *renderer, int x, int y)
{
    //Scale to window size
    SDL_Rect destin = {
        x * (config::screenWidth/config::UNSCALED_SCREEN_WIDTH),
        y * (config::screenHeight/config::UNSCALED_SCREEN_HEIGHT),
        width * (config::screenWidth/config::UNSCALED_SCREEN_WIDTH),
        height * (config::screenHeight/config::UNSCALED_SCREEN_HEIGHT)
    };
    SDL_RenderCopy(renderer, texture, NULL, &destin);
    return;
}

int Texture::getWidth()
{
    return width;
}

int Texture::getHeight()
{
    return height;
}
