#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "State.h"

class State;

class Game
{
private:
    int currentState;
    int nextState;
    State *state;

public:
    Game();
    ~Game();
    bool init();
    void quit();
    bool finished();
    void changeState();
    void setState(int newState);
    void handleEvents();
    void logic();
    void render();
};

#endif // GAME_H_INCLUDED
