#include "config.h"

namespace config
{
    bool fullscreen = false;
    int screenWidth = 960;
    int screenHeight = 540;
    const int UNSCALED_SCREEN_WIDTH = 192;
    const int UNSCALED_SCREEN_HEIGHT = 108;
}

bool config::loadConfigFile()
{
    return true;
}

void config::setDefaultValues()
{
    bool fullscreen = false;
    int screenWidth = 960;
    int screenHeight = 540;
}
