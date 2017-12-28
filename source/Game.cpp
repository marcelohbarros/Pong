#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Game.h"
#include "Title.h"
#include "Settings.h"
#include "Match.h"

const int SCREEN_WIDTH_SMALLSCREEN = 960;
const int SCREEN_HEIGHT_SMALLSCREEN = 540;

enum GameStates
{
    NONE,
    TITLE,
    SETTINGS,
    MATCH,
    QUIT
};

Game::Game()
{
    currentState = TITLE;
    nextState = NONE;
    state = NULL;
}

Game::~Game()
{
}

bool Game::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        printf("SDL not initialized: %s\n", SDL_GetError());
        return false;
    }
    if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        printf("SDL Image not initialized: %s\n", IMG_GetError());
        return false;
    }
    if(TTF_Init() == -1)
    {
        printf("SDL TTF not initialized: %s\n", TTF_GetError());
        return false;
    }
    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
    {
        printf("SDL Mixer not initialized: %s\n", Mix_GetError());
        return false;
    }

    window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH_SMALLSCREEN, SCREEN_HEIGHT_SMALLSCREEN, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        printf("Window not created! SDL error: %s\n", SDL_GetError());
        return false;
    }

    SDL_Surface *icon = IMG_Load("media/Icon.png");
    if(icon == NULL)
    {
        printf("Warning! Could not load icon. IMG Error: %s\n", IMG_GetError());
    }
    else
    {
        SDL_SetWindowIcon(window, icon);
    }
    SDL_FreeSurface(icon);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL)
    {
        printf("Renderer not created! SDL error: %s\n", SDL_GetError());
        return false;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    state = new Title(renderer);
    printf("Initiating\n");
    return true;
}

void Game::quit()
{
    delete state;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;

    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    printf("Quiting\n");
}

bool Game::finished()
{
    return (currentState == QUIT);
}

SDL_Renderer *Game::getRenderer()
{
    return renderer;
}

void Game::setState(int newState)
{
    if(newState != NONE)
    {
        nextState = newState;
    }
    return;
}

void Game::changeState()
{
    if(nextState != NONE)
    {
        if(nextState != QUIT)
        {
            delete state;
        }
        switch(nextState)
        {
            case TITLE:
                printf("Going to title\n");
                state = new Title(renderer);
                break;

            case SETTINGS:
                printf("Going to settings\n");
                state = new Settings();
                break;

            case MATCH:
                printf("Going to match\n");
                state = new Match(renderer);
                break;

            case QUIT:
                printf("Going to QUIT state\n");
                break;

            default:
                printf("Invalid state!");
                break;
        }
        currentState = nextState;
        nextState = NONE;
        printf("Changing state to %d\n", currentState);
    }
    return;
}

void Game::handleEvents()
{
    state->handleEvents();
}

void Game::logic()
{
    state->logic(this);
}

void Game::render()
{
    state->render(this);
}
