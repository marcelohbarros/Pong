#include <stdio.h>
#include "Game.h"
#include "Title.h"
#include "Settings.h"
#include "Match.h"

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
    state = new Title();
    printf("Initiating\n");
    return 1;
}

void Game::quit()
{
    printf("Quiting\n");
}

bool Game::finished()
{
    return (currentState == QUIT);
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
                state = new Title();
                break;
            case SETTINGS:
                printf("Going to settings\n");
                state = new Settings();
                break;
            case MATCH:
                printf("Going to match\n");
                state = new Match();
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
    state->render();
}
