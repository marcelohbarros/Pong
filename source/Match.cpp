#include <stdio.h>
#include <SDL.h>
#include "Match.h"

Match::Match(SDL_Renderer *renderer)
{
    background.loadTexture(renderer, "media/Match.png");
}

Match::~Match()
{
    background.free();
}

void Match::handleEvents(Game *game)
{
}

void Match::logic(Game *game)
{
    int nextState;
    scanf("%d", &nextState);
    game->setState(nextState);
    return;
}

void Match::render(Game *game)
{
    printf("I'm now at match\n");
    SDL_SetRenderDrawColor(game->getRenderer(), 0, 0, 0, 0);
    SDL_RenderClear(game->getRenderer());
    background.render(game->getRenderer());
    SDL_RenderPresent(game->getRenderer());
}
