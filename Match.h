#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED
#include "State.h"


class Match : public State
{
public:
    Match();
    ~Match();
    void handleEvents();
    void logic(Game *game);
    void render();
};

#endif //MATCH_H_INCLUDED
