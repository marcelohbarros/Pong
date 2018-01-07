#include <math.h>
#include <stdlib.h>
#include <SDL.h>
#include "Ball.h"
#include "config.h"

Ball::Ball(int x_, int y_)
{
    x = (float) x_;
    y = (float) y_;
    size = 4;

    float angle;
    bool foundAngle = false;
    while(!foundAngle)
    {
        angle = rand() % 360;
        if(angle <=  60 || angle >= 300)
        {
            foundAngle = true;
        }
        else if(angle >= 120 && angle <= 240)
        {
            foundAngle = true;
        }
    }

    angle = angle * 2 * 3.141592 / 360;
    totalSpeed = (config::UNSCALED_SCREEN_WIDTH - size) / 2; //Speed set to cross room in 2 seconds if angle = 0
    xSpeed = cosf(angle) * totalSpeed;
    ySpeed = sinf(angle) * totalSpeed;

    yCollided = false;
}

bool Ball::checkCollision(FloatRect paddle)
{
    if(x > paddle.x + paddle.w)
    {
        return false;
    }
    else if(x + size < paddle.x)
    {
        return false;
    }
    else if(y > paddle.y + paddle.h)
    {
        return false;
    }
    else if(y + size < paddle.y)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Ball::move(FloatRect paddle1, FloatRect paddle2)
{
    y += ySpeed * (SDL_GetTicks() - timer.getTicks()) * 0.001;

    //Moved into a paddle in y
    if(checkCollision(paddle1))
    {
        yCollided = true;
        ySpeed = -ySpeed;
        if(y < paddle1.y)
        {
            y = paddle1.y - size - 0.1;
        }
        else
        {
            y = paddle1.y + paddle1.h + 0.1;
        }
    }
    if(checkCollision(paddle2))
    {
        yCollided = true;
        ySpeed = -ySpeed;
        if(y < paddle2.y)
        {
            y = y - 2 * (y + size - paddle2.y);
        }
        else
        {
            y = y + 2 * (paddle2.y + paddle2.h - y);
        }
    }

    x += xSpeed * (SDL_GetTicks() - timer.getTicks()) * 0.001;

    //Moved into a paddle in x
    if(checkCollision(paddle1))
    {
        totalSpeed = totalSpeed * 1.03;
        float angle = ((y - (paddle1.y - size)) / (paddle1.h + size)) * 120 - 60; //Angle between -60 and 60 degrees
        angle = angle * 2 * 3.141592 / 360;
        xSpeed = cosf(angle) * totalSpeed;
        ySpeed = sinf(angle) * totalSpeed;
        x = paddle1.x + paddle1.w + 0.1;
    }
    if(checkCollision(paddle2))
    {
        totalSpeed = totalSpeed * 1.03;
        float angle = -((y - (paddle2.y - size)) / (paddle2.h + size)) * 120 - 120; //Angle between 120 and 240 degrees
        angle = angle * 2 * 3.141592 / 360;
        xSpeed = cosf(angle) * totalSpeed;
        ySpeed = sinf(angle) * totalSpeed;
        x = paddle2.x - size - 0.1;
    }

    //Moved outside the level
    if(y < 0)
    {
        y = -y;
        ySpeed = -ySpeed;
    }
    else if(y > config::UNSCALED_SCREEN_HEIGHT - size)
    {
        y = y - 2 * (y - (config::UNSCALED_SCREEN_HEIGHT - size));
        ySpeed = -ySpeed;
    }
    timer.update();
}

void Ball::render(SDL_Renderer *renderer)
{
    //Scale to window size
    SDL_Rect destin = {
        (int) round(x * (config::screenWidth/config::UNSCALED_SCREEN_WIDTH)),
        (int) round(y * (config::screenHeight/config::UNSCALED_SCREEN_HEIGHT)),
        (int) round(size * (config::screenWidth/config::UNSCALED_SCREEN_WIDTH)),
        (int) round(size * (config::screenHeight/config::UNSCALED_SCREEN_HEIGHT))
    };
    SDL_RenderFillRect(renderer, &destin);
}

int Ball::goal()
{
    if(x < -size)
    {
        return PLAYER_2;
    }
    else if(x > config::UNSCALED_SCREEN_WIDTH + size)
    {
        return PLAYER_1;
    }
    else
    {
        return NONE;
    }
}

FloatRect Ball::getBallBox()
{
    return {x, y, size, size};
}
