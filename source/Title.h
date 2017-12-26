#ifndef TITLE_H_INCLUDED
#define TITLE_H_INCLUDED
#include "State.h"


class Title : public State
{
public:
    Title();
    ~Title();
    void handleEvents();
    void logic(Game *game);
    void render(Game *game);
};

#endif //TITLE_H_INCLUDED
