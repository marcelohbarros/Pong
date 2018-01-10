#include <SDL.h>
#include <stdio.h>
#include <sstream>
#include <string>
#include "Match.h"

Match::Match(SDL_Renderer *renderer) :
    player1Paddle(new Paddle(10, 44, 1)),
    player2Paddle(new Paddle(177, 44, 2))
{
    background.loadTexture(renderer, "media/Match.png");
    player1Score = 0;
    player2Score = 0;
    startTimer.update();
    started = false;
    playing = false;
    goal = Mix_LoadWAV("media/Goal.wav");
    hit = Mix_LoadWAV("media/Hit.wav");
    numberFont = TTF_OpenFont("media/NumberHoffont.ttf", 24);
    std::stringstream ssPlayer1;
    ssPlayer1 << player1Score;
    std::stringstream ssPlayer2;
    ssPlayer2 << player2Score;
    player1ScoreTexture.loadTexture(renderer, numberFont, ssPlayer1.str());
    player2ScoreTexture.loadTexture(renderer, numberFont, ssPlayer2.str());
}

Match::~Match()
{
    delete player1Paddle;
    delete player2Paddle;
    delete ball;
    Mix_FreeChunk(goal);
    goal = NULL;
    Mix_FreeChunk(hit);
    hit = NULL;
    TTF_CloseFont(numberFont);
    numberFont = NULL;
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
        if(playing)
        {
            player1Paddle->handleInput(e);
            player2Paddle->handleInput(e);
        }
    }
}

//Check for goals, then move
void Match::logic(Game *game)
{
    if(playing && (ball->goal() != Ball::NONE))
    {
        if(ball->goal() == Ball::PLAYER_1)
        {
            player1Score ++;
            std::stringstream ss;
            ss << player1Score;
            player1ScoreTexture.loadTexture(game->getRenderer(), numberFont, ss.str());
        }
        else
        {
            player2Score++;
            std::stringstream ss;
            ss << player2Score;
            player2ScoreTexture.loadTexture(game->getRenderer(), numberFont, ss.str());
        }
        delete ball;
        delete player1Paddle;
        player1Paddle = new Paddle(10, 44, 1);
        delete player2Paddle;
        player2Paddle = new Paddle(177, 44, 2);
        playing = false;
        goalTimer.update();
        Mix_PlayChannel(-1, goal, 0);
    }

    //Wait 1 second before start and 0.5 seconds after goals
    if(!started && SDL_GetTicks() - startTimer.getTicks() > 1000)
    {
        started = true;
        playing = true;
        ball = new Ball(94, 52);
    }
    else if(!playing && started && SDL_GetTicks() - goalTimer.getTicks() > 500)
    {
        playing = true;
        ball = new Ball(94, 52);
    }

    if(playing)
    {
        player1Paddle->move(ball->getBallBox());
        player2Paddle->move(ball->getBallBox());
        ball->move(player1Paddle->getPaddleBox(), player2Paddle->getPaddleBox());
        if(ball->collided())
        {
            Mix_PlayChannel(-1, hit, 0);
        }
    }
    return;
}

void Match::render(Game *game)
{
    SDL_SetRenderDrawColor(game->getRenderer(), 255, 255, 255, 255);
    SDL_RenderClear(game->getRenderer());
    background.render(game->getRenderer());
    player1ScoreTexture.render(game->getRenderer(), config::UNSCALED_SCREEN_WIDTH/2 + 1 - 14 - player1ScoreTexture.getWidth(), 4);
    player2ScoreTexture.render(game->getRenderer(), config::UNSCALED_SCREEN_WIDTH/2 + 1 + 14, 4);
    player1Paddle->render(game->getRenderer());
    player2Paddle->render(game->getRenderer());
    if (playing)
    {
        ball->render(game->getRenderer());
    }
    SDL_RenderPresent(game->getRenderer());
}
