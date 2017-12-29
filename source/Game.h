#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL.h>
#include "State.h"

class State;

class Game
{
private:
    int currentState;
    int nextState;
    State *state;
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    enum GameStates {NONE, TITLE, SETTINGS, MATCH, QUIT};

    Game();
    ~Game();
    bool init();
    void quit();
    bool finished();
    SDL_Renderer *getRenderer();
    void changeState();
    void setState(int newState);
    void handleEvents();
    void logic();
    void render();
};

#endif // GAME_H_INCLUDED
