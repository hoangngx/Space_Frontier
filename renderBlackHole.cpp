#include "renderBlackHole.h"

renderBlackHole::renderBlackHole()
{
    sprite.setTextureRect(sf::IntRect(0, 0, 68, 70));
    sprite.setPosition(-10, 232);
}

void renderBlackHole::isReady()
{
    sprite.setTextureRect(sf::IntRect(72, 0, 68, 70));
    sprite.setPosition(-21, 232);
}

void renderBlackHole::isNotReady()
{
    sprite.setTextureRect(sf::IntRect(0, 0, 68, 70));
    sprite.setPosition(-10, 232);
}
