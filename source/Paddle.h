#ifndef PADDLE_H_INCLUDED
#define PADDLE_H_INCLUDED
#include <SDL.h>
#include "Timer.h"
#include "FloatRect.h"

class Paddle
{
private:
    float x;
    float y;
    float width;
    float height;
    float speed;
    int UP_BUTTON;
    int DOWN_BUTTON;
    bool upButtonPressed;
    bool downButtonPressed;
    Timer timer;
    bool checkCollision(FloatRect ball);
public:
    Paddle(int x_, int y_, int player);
    void handleInput(SDL_Event e);
    void move(FloatRect ball);
    void render(SDL_Renderer *renderer);
    FloatRect getPaddleBox();
};

#endif // PADDLE_H_INCLUDED
