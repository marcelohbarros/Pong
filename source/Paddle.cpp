#include <math.h>
#include <SDL.h>
#include "Paddle.h"
#include "Timer.h"
#include "FloatRect.h"
#include "config.h"

Paddle::Paddle(int x_, int y_, int player)
{
    x = (float) x_;
    y = (float) y_;
    width = 4;
    height = 20;
    speed = 0;

    if(player == 1)
    {
        UP_BUTTON = SDLK_w;
        DOWN_BUTTON = SDLK_s;
    }
    else
    {
        UP_BUTTON = SDLK_UP;
        DOWN_BUTTON = SDLK_DOWN;
    }

    upButtonPressed = false;
    downButtonPressed = false;
}

//Speed set to cross the entire room in 1 second
void Paddle::handleInput(SDL_Event e)
{
    if(e.type == SDL_KEYDOWN)
    {
        if(e.key.keysym.sym == DOWN_BUTTON && !downButtonPressed)
        {
            speed += (config::UNSCALED_SCREEN_HEIGHT - height) / 1;
            downButtonPressed = true;
        }
        else if(e.key.keysym.sym == UP_BUTTON && !upButtonPressed)
        {
            speed -= (config::UNSCALED_SCREEN_HEIGHT - height) / 1;
            upButtonPressed = true;
        }
    }
    else if(e.type == SDL_KEYUP)
    {
        if(e.key.keysym.sym == DOWN_BUTTON && downButtonPressed)
        {
            speed -= (config::UNSCALED_SCREEN_HEIGHT - height) / 1;
            downButtonPressed = false;
        }
        else if(e.key.keysym.sym == UP_BUTTON && upButtonPressed)
        {
            speed += (config::UNSCALED_SCREEN_HEIGHT - height) / 1;
            upButtonPressed = false;
        }
    }
}

bool Paddle::checkCollision(FloatRect ball)
{
    if(x > ball.x + ball.w)
    {
        return false;
    }
    else if(x + width < ball.x)
    {
        return false;
    }
    else if(y > ball.y + ball.h)
    {
        return false;
    }
    else if(y + height < ball.y)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Paddle::move(FloatRect ball)
{
    y += speed * (SDL_GetTicks() - timer.getTicks()) * 0.001;

    //Moved into the ball
    if(checkCollision(ball))
    {
        if(y > ball.y)
        {
            y = ball.y + ball.h + 0.1;
        }
        else
        {
            y = ball.y - height - 0.1;
        }
    }

    //Moved outside the level
    if(y < 0)
    {
        y = 0;
    }
    if(y > config::UNSCALED_SCREEN_HEIGHT - height)
    {
        y = config::UNSCALED_SCREEN_HEIGHT - height;
    }
    timer.update();
}

void Paddle::render(SDL_Renderer *renderer)
{
    //Scale to window size
    SDL_Rect destin = {
        (int) round(x * (config::screenWidth/config::UNSCALED_SCREEN_WIDTH)),
        (int) round(y * (config::screenHeight/config::UNSCALED_SCREEN_HEIGHT)),
        (int) round(width * (config::screenWidth/config::UNSCALED_SCREEN_WIDTH)),
        (int) round(height * (config::screenHeight/config::UNSCALED_SCREEN_HEIGHT))
    };

    SDL_RenderFillRect(renderer, &destin);
}

FloatRect Paddle::getPaddleBox()
{
    return {x, y, width, height};
}
