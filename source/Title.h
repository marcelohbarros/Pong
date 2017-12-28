#ifndef TITLE_H_INCLUDED
#define TITLE_H_INCLUDED
#include <SDL.h>
#include "State.h"
#include "Texture.h"

class Title : public State
{
private:
    Texture background;
public:
    Title(SDL_Renderer *renderer);
    ~Title();
    void handleEvents();
    void logic(Game *game);
    void render(Game *game);
};

#endif //TITLE_H_INCLUDED
