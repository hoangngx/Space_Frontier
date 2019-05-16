#include "blackhole.h"

blackhole::blackhole()
{
    rect.setSize(sf::Vector2f(65, 60));
    rect.setPosition(0,0);
    sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
}

void blackhole::update()
{
    sprite.setPosition(rect.getPosition());
}

void blackhole::updateCoin(int &spaceship$)
{
    spaceship$ -= BlackHoleCost;
}
