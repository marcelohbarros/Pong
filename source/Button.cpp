#include <SDL.h>
#include "Button.h"
#include "ImageTexture.h"

Button::Button(int x_, int y_)
{
    x = x_;
    y = y_;
    width = 0;
    height = 0;
    selected = false;
}

Button::~Button()
{
    selectedTexture.free();
    unselectedTexture.free();
}

void Button::loadSelectedTexture(SDL_Renderer *renderer, std::string path)
{
    selectedTexture.loadTexture(renderer, path);
    width = selectedTexture.getWidth();
    height = selectedTexture.getHeight();
    return;
}

void Button::loadUnselectedTexture(SDL_Renderer *renderer, std::string path)
{
    unselectedTexture.loadTexture(renderer, path);
    width = unselectedTexture.getWidth();
    height = unselectedTexture.getHeight();
    return;
}

void Button::select()
{
    selected = true;
    return;
}

void Button::unselect()
{
    selected = false;
    return;
}

bool Button::isSelected()
{
    return selected;
}

void Button::render(SDL_Renderer *renderer)
{
    if(selected)
    {
        selectedTexture.render(renderer, x, y);
    }
    else
    {
        unselectedTexture.render(renderer, x, y);
    }
    return;
}
