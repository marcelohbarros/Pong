#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "ImageTexture.h"
#include "config.h"

ImageTexture::ImageTexture()
{
    texture = NULL;
    width = 0;
    height = 0;
}

ImageTexture::~ImageTexture()
{
    free();
}

void ImageTexture::loadTexture(SDL_Renderer *renderer, std::string path)
{
    free();
    SDL_Surface *surface = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    width = surface->w;
    height = surface->h;
    SDL_FreeSurface(surface);
    return;
}

void ImageTexture::free()
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

void ImageTexture::render(SDL_Renderer *renderer, int x, int y)
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

int ImageTexture::getWidth()
{
    return width;
}

int ImageTexture::getHeight()
{
    return height;
}
