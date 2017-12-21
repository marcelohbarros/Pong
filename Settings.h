#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED
#include "State.h"


class Settings : public State
{
public:
    Settings();
    ~Settings();
    void handleEvents();
    void logic(Game *game);
    void render();
};

#endif //SETTINGS_H_INCLUDED
