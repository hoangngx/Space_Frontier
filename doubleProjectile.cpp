#include "doubleProjectile.h"

doubleProjectile::doubleProjectile()
{
    sprite.setTextureRect(sf::IntRect(0, 0, 55, 70));
    sprite.setPosition(-9,165);
}

void doubleProjectile::update(int &Spaceship1$, int &projectileDamage)
{
    sprite.setTextureRect(sf::IntRect(0, 0, 0, 0)); // disappear when updated to be replaced by speed up
    Spaceship1$ -= DoubleProjectilePrice;
    projectileDamage = 2;
}

void doubleProjectile::isReady()
{
    sprite.setTextureRect(sf::IntRect(57, 0, 55, 70));
    sprite.setPosition(-9,165);
}

void doubleProjectile::isNotReady()
{
    sprite.setTextureRect(sf::IntRect(0, 0, 55, 70));
    sprite.setPosition(-9,165);
}
