#include "spaceship.h"
#include "random.h"

spaceship::spaceship()
{
    rect.setPosition(270, 470);
    sprite.setTextureRect(sf::IntRect(15, 125*generateRandomSpaceship() + 10, 122, 122));
    rect.setSize(sf::Vector2f(100, 110));
}

void spaceship::update()
{
    sprite.setPosition(rect.getPosition());
}

void spaceship::updateMovement()
{
        // use keyboard to move spaceShip
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (canMoveLeft == true)
            {
            rect.move(-shipSpeed,0);
            direction = 1;
            canMoveLeft = true;
            canMoveRight = true;
            canMoveDown = true;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (canMoveRight == true)
            {
            rect.move(shipSpeed,0);
            direction = 2;
            canMoveLeft = true;
            canMoveDown = true;
            canMoveRight = true;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            rect.move(0,-shipSpeed);
            direction = 3;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (canMoveDown == true)
            {
            rect.move(0,shipSpeed);
            direction = 4;
            canMoveLeft = true;
            canMoveDown = true;
            canMoveRight = true;
            }
        }
}
