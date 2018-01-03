#include <SDL.h>
#include "Settings.h"

Settings::Settings()
{
}

Settings::~Settings()
{
}

void Settings::handleEvents(Game *game)
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

void Settings::logic(Game *game)
{
    return;
}

void Settings::render(Game *game)
{
    SDL_SetRenderDrawColor(game->getRenderer(), 0, 0, 0, 0);
    SDL_RenderClear(game->getRenderer());
    SDL_RenderPresent(game->getRenderer());
}
