#include <stdio.h>
#include <SDL.h>
#include "Title.h"

Title::Title(SDL_Renderer *renderer)
{
    background.loadTexture(renderer, "media/Title.png");
}

Title::~Title()
{
    background.free();
}

void Title::handleEvents()
{
}

void Title::logic(Game *game)
{
    int nextState;
    scanf("%d", &nextState);
    game->setState(nextState);
    return;
}

void Title::render(Game *game)
{
    printf("I'm now at title\n");
    SDL_SetRenderDrawColor(game->getRenderer(), 0, 0, 0, 0);
    SDL_RenderClear(game->getRenderer());
    background.render(game->getRenderer());
    SDL_RenderPresent(game->getRenderer());
}
