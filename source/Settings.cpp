#include <stdio.h>
#include <SDL.h>
#include "Settings.h"

Settings::Settings()
{
}

Settings::~Settings()
{
}

void Settings::handleEvents()
{
}

void Settings::logic(Game *game)
{
    int nextState;
    scanf("%d", &nextState);
    game->setState(nextState);
    return;
}

void Settings::render(Game *game)
{
    printf("I'm now at settings\n");
    SDL_SetRenderDrawColor(game->getRenderer(), 0, 0, 0, 0);
    SDL_RenderClear(game->getRenderer());
    SDL_RenderPresent(game->getRenderer());
}
