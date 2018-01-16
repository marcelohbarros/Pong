#include <SDL.h>
#include "config.h"

namespace config
{
    bool fullscreen = false;
    int screenWidth = 960;
    int screenHeight = 540;
    const int UNSCALED_SCREEN_WIDTH = 192;
    const int UNSCALED_SCREEN_HEIGHT = 108;
}

void config::toggleFullScreen()
{
    if(!fullscreen)
    {
        SDL_DisplayMode current;
        SDL_GetCurrentDisplayMode(0, &current);
        screenWidth = current.w;
        screenHeight = current.h;
        fullscreen = true;
    }
    else
    {
        screenWidth = 960;
        screenHeight = 540;
        fullscreen = false;
    }
    return;
}
