#include "enemy.h"
#include "random.h"

enemy::enemy()
{
    rect.setPosition(generateRandomX(), -300);
    sprite.setTextureRect(sf::IntRect(30, 40, 180, 190));
    rect.setSize(sf::Vector2f(60, 75));
}

void enemy::update()
{
    sprite.setPosition(rect.getPosition());
}

void enemy::updateMovement()
{
        rect.move(0, enemySpeed); // down
}

