#include <stdio.h>
#include <SDL.h>
#include "Title.h"
#include "Button.h"

enum buttons
{
    PLAY_BUTTON,
    SETTINGS_BUTTON,
    QUIT_BUTTON
};

Title::Title(SDL_Renderer *renderer)
{
    selectedButton = PLAY_BUTTON;
    background.loadTexture(renderer, "media/Title.png");

    button[PLAY_BUTTON].loadSelectedTexture(renderer, "media/PlayButtonSelected.png");
    button[PLAY_BUTTON].loadUnselectedTexture(renderer, "media/PlayButtonUnselected.png");
    button[PLAY_BUTTON].setPosition(72, 34);
    button[PLAY_BUTTON].select();

    button[SETTINGS_BUTTON].loadSelectedTexture(renderer, "media/SettingsButtonSelected.png");
    button[SETTINGS_BUTTON].loadUnselectedTexture(renderer, "media/SettingsButtonUnselected.png");
    button[SETTINGS_BUTTON].setPosition(72, 52);

    button[QUIT_BUTTON].loadSelectedTexture(renderer, "media/QuitButtonSelected.png");
    button[QUIT_BUTTON].loadUnselectedTexture(renderer, "media/QuitButtonUnselected.png");
    button[QUIT_BUTTON].setPosition(72, 70);
}

Title::~Title()
{
    background.free();
}

void Title::handleEvents(Game *game)
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
            if(e.key.keysym.sym == SDLK_DOWN)
            {
                switch(selectedButton)
                {
                    case PLAY_BUTTON:
                        selectedButton = SETTINGS_BUTTON;
                        break;
                    case SETTINGS_BUTTON:
                        selectedButton = QUIT_BUTTON;
                        break;
                    case QUIT_BUTTON:
                        selectedButton = PLAY_BUTTON;
                        break;
                }
            }
            else if(e.key.keysym.sym == SDLK_UP)
            {
                switch(selectedButton)
                {
                    case PLAY_BUTTON:
                        selectedButton = QUIT_BUTTON;
                        break;
                    case SETTINGS_BUTTON:
                        selectedButton = PLAY_BUTTON;
                        break;
                    case QUIT_BUTTON:
                        selectedButton = SETTINGS_BUTTON;
                        break;
                }
            }
            else if(e.key.keysym.sym == SDLK_RETURN)
            {
                switch(selectedButton)
                {
                    case PLAY_BUTTON:
                        game->setState(Game::MATCH);
                        break;
                    case SETTINGS_BUTTON:
                        game->setState(Game::SETTINGS);
                        break;
                    case QUIT_BUTTON:
                        game->setState(Game::QUIT);
                        break;
                }
            }
        }
    }
}

//Change buttons if selectedButton was changed
void Title::logic(Game *game)
{
    if(!button[selectedButton].isSelected())
    {
        button[PLAY_BUTTON].unselect();
        button[SETTINGS_BUTTON].unselect();
        button[QUIT_BUTTON].unselect();
        button[selectedButton].select();
    }
    return;
}

void Title::render(Game *game)
{
    SDL_SetRenderDrawColor(game->getRenderer(), 0, 0, 0, 0);
    SDL_RenderClear(game->getRenderer());

    background.render(game->getRenderer());
    button[PLAY_BUTTON].render(game->getRenderer());
    button[SETTINGS_BUTTON].render(game->getRenderer());
    button[QUIT_BUTTON].render(game->getRenderer());

    SDL_RenderPresent(game->getRenderer());
}
