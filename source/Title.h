#ifndef TITLE_H_INCLUDED
#define TITLE_H_INCLUDED
#include <SDL.h>
#include <SDL_mixer.h>
#include "State.h"
#include "ImageTexture.h"
#include "Button.h"

class Title : public State
{
private:
    ImageTexture background;
    Button button[3];
    int selectedButton;
    Mix_Chunk *changeSelection;
    Mix_Chunk *select;
    bool changedState;
    bool playedAudio;
    int nextState;
public:
    Title(SDL_Renderer *renderer, int previousState = Game::NONE);
    ~Title();
    void handleEvents(Game *game);
    void logic(Game *game);
    void render(Game *game);
};

#endif //TITLE_H_INCLUDED
