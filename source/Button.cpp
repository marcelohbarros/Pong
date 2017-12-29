#include <SDL.h>
#include "Button.h"
#include "Texture.h"

Button::Button()
{
    x = 0;
    y = 0;
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

void Button::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
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
