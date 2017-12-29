#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED
#include "Game.h"

class Game;

class State
{
public:
    virtual void handleEvents(Game *game)= 0;
    virtual void logic(Game *game) = 0;
    virtual void render(Game *game) = 0;
    virtual ~State(){};
};

#endif // STATE_H_INCLUDED
