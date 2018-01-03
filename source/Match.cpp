#include <SDL.h>
#include "Match.h"

Match::Match(SDL_Renderer *renderer)
{
    background.loadTexture(renderer, "media/Match.png");
}

Match::~Match()
{
}

void Match::handleEvents(Game *game)
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
        {
            game->setState(Game::QUIT);
        }
        else if(e.type == SDL_KEYDOWN)
        {
            if(e.key.keysym.sym == SDLK_ESCAPE)
            {
                game->setState(Game::TITLE);
            }
        }
    }
}

void Match::logic(Game *game)
{
    return;
}

void Match::render(Game *game)
{
    SDL_SetRenderDrawColor(game->getRenderer(), 0, 0, 0, 0);
    SDL_RenderClear(game->getRenderer());
    background.render(game->getRenderer());
    SDL_RenderPresent(game->getRenderer());
}
