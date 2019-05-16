#include "projectile.h"
#include "random.h"

projectile::projectile()
{
    rect.setSize(sf::Vector2f(20, 40));
    rect.setPosition(0,0);
    sprite.setTextureRect(sf::IntRect(182, 727, 100, 100));
}

void projectile::doubleFire()
{
    rect.setSize(sf::Vector2f(20, 40));
    rect.setPosition(0,0);
    sprite.setTextureRect(sf::IntRect(170, 600, 100, 100));
}

void projectile::update()
{
    if (direction == 1 || direction == 0) // Left
    {
        rect.move(0, -projectileSpeed);
        sprite.move(0, -projectileSpeed);
    }
    if (direction == 2) // Right
    {
        rect.move(0, -projectileSpeed);
        sprite.move(0, -projectileSpeed);
    }
    if (direction == 3) // Up
    {
        rect.move(0, -projectileSpeed);
        sprite.move(0, -projectileSpeed);
    }
    if (direction == 4) //Down
    {
        rect.move(0, -projectileSpeed);
        sprite.move(0, -projectileSpeed);
    }

    counterLifetime++;
    if (counterLifetime >= Lifetime)
    {
        destroy = true;
    }

    sprite.setPosition(rect.getPosition());
}
