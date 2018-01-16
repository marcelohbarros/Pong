#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

namespace config
{
    extern bool fullscreen;
    extern int screenWidth;
    extern int screenHeight;
    extern const int UNSCALED_SCREEN_WIDTH;
    extern const int UNSCALED_SCREEN_HEIGHT;

    void toggleFullScreen();
}

#endif // CONFIG_H_INCLUDED
