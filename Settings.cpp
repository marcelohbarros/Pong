#include <stdio.h>
#include "Settings.h"

Settings::Settings()
{
}

Settings::~Settings()
{
}

void Settings::handleEvents()
{
}

void Settings::logic(Game *game)
{
    int aaaa;
    scanf("%d", &aaaa);
    game->setState(aaaa);
    return;
}

void Settings::render()
{
    printf("I'm now at settings\n");
}
