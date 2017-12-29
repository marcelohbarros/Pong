#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include <SDL.h>
#include "Texture.h"

class Button
{
private:
    Texture selectedTexture;
    Texture unselectedTexture;
    int x;
    int y;
    int width;
    int height;
    bool selected;
public:
    Button();
    ~Button();
    void loadSelectedTexture(SDL_Renderer *renderer, std::string path);
    void loadUnselectedTexture(SDL_Renderer *renderer, std::string path);
    void setPosition(int x, int y);
    void select();
    void unselect();
    bool isSelected();
    void render(SDL_Renderer *renderer);
};

#endif //BUTTON_H_INCLUDED
