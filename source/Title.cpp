#include <stdio.h>
#include "Title.h"

Title::Title()
{
}

Title::~Title()
{
}

void Title::handleEvents()
{
}

void Title::logic(Game *game)
{
    int aaaa;
    scanf("%d", &aaaa);
    game->setState(aaaa);
    return;
}

void Title::render()
{
    printf("I'm now at title\n");
}
