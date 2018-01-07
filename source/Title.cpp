#include <SDL.h>
#include <SDL_mixer.h>
#include "Title.h"
#include "Button.h"

enum buttons
{
    PLAY_BUTTON,
    SETTINGS_BUTTON,
    QUIT_BUTTON
};

Title::Title(SDL_Renderer *renderer, int previousState) : button{{73, 34}, {73, 52}, {73, 70}}
{
    background.loadTexture(renderer, "media/Title.png");

    button[PLAY_BUTTON].loadSelectedTexture(renderer, "media/PlayButtonSelected.png");
    button[PLAY_BUTTON].loadUnselectedTexture(renderer, "media/PlayButtonUnselected.png");

    button[SETTINGS_BUTTON].loadSelectedTexture(renderer, "media/SettingsButtonSelected.png");
    button[SETTINGS_BUTTON].loadUnselectedTexture(renderer, "media/SettingsButtonUnselected.png");

    button[QUIT_BUTTON].loadSelectedTexture(renderer, "media/QuitButtonSelected.png");
    button[QUIT_BUTTON].loadUnselectedTexture(renderer, "media/QuitButtonUnselected.png");

    switch(previousState)
    {
        case Game::NONE:
        case Game::MATCH:
            button[PLAY_BUTTON].select();
            selectedButton = PLAY_BUTTON;
            break;
        case Game::SETTINGS:
            button[SETTINGS_BUTTON].select();
            selectedButton = SETTINGS_BUTTON;
            break;
    }

    changeSelection = Mix_LoadWAV("media/ChangeSelection.wav");
    select = Mix_LoadWAV("media/Select.wav");
    nextState = Game::NONE;
    changedState = false;
    playedAudio = false;
}

Title::~Title()
{
    Mix_FreeChunk(changeSelection);
    changeSelection = NULL;
    Mix_FreeChunk(select);
    select = NULL;
}

void Title::handleEvents(Game *game)
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
        {
            changedState = true;
            nextState = Game::QUIT;
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
                changedState = true;
                switch(selectedButton)
                {
                    case PLAY_BUTTON:
                        nextState = Game::MATCH;
                        break;
                    case SETTINGS_BUTTON:
                        nextState = Game::SETTINGS;
                        break;
                    case QUIT_BUTTON:
                        nextState = Game::QUIT;
                        break;
                }
            }
        }
    }
}

//Change buttons if selectedButton was changed, then play audio if a button was selected
void Title::logic(Game *game)
{
    if(!changedState)
    {
        if(!button[selectedButton].isSelected())
        {
            Mix_PlayChannel(-1, changeSelection, 0);
            button[PLAY_BUTTON].unselect();
            button[SETTINGS_BUTTON].unselect();
            button[QUIT_BUTTON].unselect();
            button[selectedButton].select();
        }
    }
    else if(!playedAudio && nextState != Game::QUIT)
    {
        Mix_PlayChannel(-1, select, 0);
        playedAudio = true;
    }
    else if(Mix_Playing(-1) == 0)
    {
        game->setState(nextState);
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
