#include "coin.h"

coin::coin()
{
    sprite.setTextureRect(sf::IntRect(0, 0, 23, 25));
}
void coin::updateMovement()
{
        counter2++;
        if (counter2 == 4) // 4 is coin spinning speed (the higher the slower)
        {
            sprite.setTextureRect(sf::IntRect(24*0, 0, 24, 25));
        }
        if (counter2 == 8)
        {
            sprite.setTextureRect(sf::IntRect(24*1, 0, 24, 25));
        }
        if (counter2 == 12)
        {
            sprite.setTextureRect(sf::IntRect(24*2, 0, 24, 25));
        }
        if (counter2 == 16)
        {
            sprite.setTextureRect(sf::IntRect(24*3, 0, 24, 25));
        }
        if (counter2 == 20)
        {
            sprite.setTextureRect(sf::IntRect(24*4, 0, 24, 25));
        }
        if (counter2 == 24)
        {
            sprite.setTextureRect(sf::IntRect(24*5, 0, 24, 25));
        }
        if (counter2 == 24)
        {
            counter2 = 0;
        }
        counter++;
        if (counter >= lifetime)
        {
            isCoin = false;
        }
}

