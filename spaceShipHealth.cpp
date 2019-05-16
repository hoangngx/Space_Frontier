#include "spaceShipHealth.h"

spaceShipHealth::spaceShipHealth()
{
    sprite.setTextureRect(sf::IntRect(0, 0, 85, 6));
    rect.setSize(sf::Vector2f(100, 110));
}

void spaceShipHealth::update() // -20% HP
{
    counter++;
    if (counter > 5)
    {
        counter = 5;
    }
    sprite.setTextureRect(sf::IntRect(85*counter, 0, 85, 6));
}

void spaceShipHealth::powerUp() // +20% HP
{
    counter--;
    if (counter < 0) // HP cannot exceed the maximum
    {
        counter = 0;
    }
    sprite.setTextureRect(sf::IntRect(85*counter, 0, 85, 6));
}

