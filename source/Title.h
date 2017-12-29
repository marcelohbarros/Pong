#ifndef TITLE_H_INCLUDED
#define TITLE_H_INCLUDED
#include <SDL.h>
#include "State.h"
#include "Texture.h"
#include "Button.h"

class Title : public State
{
private:
    Texture background;
    Button button[3];
    int selectedButton;
public:
    Title(SDL_Renderer *renderer);
    ~Title();
    void handleEvents(Game *game);
    void logic(Game *game);
    void render(Game *game);
};

#endif //TITLE_H_INCLUDED
