#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED
#include <SDL.h>
#include "State.h"
#include "Texture.h"

class Match : public State
{
private:
    Texture background;
public:
    Match(SDL_Renderer *renderer);
    ~Match();
    void handleEvents(Game *game);
    void logic(Game *game);
    void render(Game *game);
};

#endif //MATCH_H_INCLUDED
