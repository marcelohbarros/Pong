#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "TextTexture.h"
#include "config.h"

TextTexture::TextTexture()
{
    texture = NULL;
    width = 0;
    height = 0;
}

TextTexture::~TextTexture()
{
    free();
}

void TextTexture::loadTexture(SDL_Renderer *renderer, TTF_Font *font, std::string text_, SDL_Color color)
{
    free();
    SDL_Surface *surface = TTF_RenderText_Solid(font, text_.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    width = surface->w;
    height = surface->h;
    text = text_;
    SDL_FreeSurface(surface);
    return;
}

void TextTexture::free()
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

void TextTexture::render(SDL_Renderer *renderer, int x, int y)
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

int TextTexture::getWidth()
{
    return width;
}

int TextTexture::getHeight()
{
    return height;
}

std::string TextTexture::getText()
{
    return text;
}
