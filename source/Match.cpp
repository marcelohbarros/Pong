#include <stdio.h>
#include "Match.h"

Match::Match()
{
}

Match::~Match()
{
}

void Match::handleEvents()
{
}

void Match::logic(Game *game)
{
    int aaaa;
    scanf("%d", &aaaa);
    game->setState(aaaa);
    return;
}

void Match::render(Game *game)
{
    printf("I'm now at match\n");
}
