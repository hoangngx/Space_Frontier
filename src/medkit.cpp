#include "medkit.h"

medkit::medkit()
{
    sprite.setTextureRect(sf::IntRect(0, 0, 51, 63));
    sprite.setPosition(1,90);
}

void medkit::update(int &Spaceship1$,int &spaceShipHp)
{
    sprite.setTextureRect(sf::IntRect(0, 0, 51, 63)); // update symbol
    Spaceship1$ -= medkitPrice; // Reduce coin
    spaceShipHp += 2; // Hp Up
    if (spaceShipHp >= 10)
    {
        spaceShipHp = 10;
    }
}

void medkit::isReady()
{
    sprite.setTextureRect(sf::IntRect(52, 0, 51, 63)); // Hp up is ready to use
}

void medkit::isNotReady()
{
    sprite.setTextureRect(sf::IntRect(0, 0, 51, 63)); // Hp up is ready to use
}
