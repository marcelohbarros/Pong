#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED
#include <SDL.h>
#include "Timer.h"
#include "FloatRect.h"
#include "config.h"

class Ball
{
private:
    float x;
    float y;
    int size;
    float totalSpeed;
    float xSpeed;
    float ySpeed;
    Timer timer;
    bool yCollided;
public:
    enum Player {NONE, PLAYER_1, PLAYER_2};

    Ball();
    Ball(int x_, int y_);
    bool checkCollision(FloatRect paddle);
    void move(FloatRect paddle1, FloatRect paddle2);
    void render(SDL_Renderer *renderer);
    int goal();
    FloatRect getBallBox();
};

#endif // BALL_H_INCLUDED
