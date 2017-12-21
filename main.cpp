#include <stdio.h>
#include <iostream>
#include "Game.h"

int main(int argc, char* args)
{
    Game *game = new Game();
    if(game->init())
    {
        while(!game->finished())
        {
            game->handleEvents();
            game->logic();
            game->changeState();
            game->render();
        }
    }
    game->quit();
    return 0;
}
