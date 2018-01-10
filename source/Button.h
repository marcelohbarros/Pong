#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include <SDL.h>
#include "ImageTexture.h"

class Button
{
private:
    ImageTexture selectedTexture;
    ImageTexture unselectedTexture;
    int x;
    int y;
    int width;
    int height;
    bool selected;
public:
    Button(int x_, int y_);
    ~Button();
    void loadSelectedTexture(SDL_Renderer *renderer, std::string path);
    void loadUnselectedTexture(SDL_Renderer *renderer, std::string path);
    void select();
    void unselect();
    bool isSelected();
    void render(SDL_Renderer *renderer);
};

#endif //BUTTON_H_INCLUDED
