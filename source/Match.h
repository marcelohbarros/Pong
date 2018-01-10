#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "State.h"
#include "ImageTexture.h"
#include "Paddle.h"
#include "Ball.h"
#include "TextTexture.h"

class Match : public State
{
private:
    ImageTexture background;
    Paddle *player1Paddle;
    Paddle *player2Paddle;
    Ball *ball;
    int player1Score;
    int player2Score;
    Timer startTimer;
    Timer goalTimer;
    bool started;
    bool playing;
    Mix_Chunk *goal;
    Mix_Chunk *hit;
    TTF_Font *numberFont;
    TextTexture player1ScoreTexture;
    TextTexture player2ScoreTexture;
public:
    Match(SDL_Renderer *renderer);
    ~Match();
    void handleEvents(Game *game);
    void logic(Game *game);
    void render(Game *game);
};

#endif //MATCH_H_INCLUDED
