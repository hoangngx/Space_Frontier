#include "speedUp.h"

speedUp::speedUp()
{
    sprite.setTextureRect(sf::IntRect(0, 0, 65, 70));
    sprite.setPosition(-120,165);
}

void speedUp::update(int &spaceShip$, int &projectileSpeed, int &projectileRange)
{
    sprite.setTextureRect(sf::IntRect(0, 0, 1, 1));
    sprite.setPosition(-12, 165);
    spaceShip$ -= speedUpcost;
    projectileSpeed = 45;
    projectileRange = 7;
}

void speedUp::isReady()
{
    sprite.setTextureRect(sf::IntRect(70, 0, 65, 70));
    sprite.setPosition(4,165);
}
