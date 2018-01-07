#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED
#include <SDL.h>
#include <SDL_mixer.h>
#include "State.h"
#include "Texture.h"
#include "Paddle.h"
#include "Ball.h"

class Match : public State
{
private:
    Texture background;
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
public:
    Match(SDL_Renderer *renderer);
    ~Match();
    void handleEvents(Game *game);
    void logic(Game *game);
    void render(Game *game);
};

#endif //MATCH_H_INCLUDED
