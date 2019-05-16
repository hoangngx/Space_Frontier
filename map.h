#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef BACKGROUND_H
#define BACKGROUND_H


class background
{
    public:
        sf::Sprite sprite;
        background();
        void updateMovement(double &speed);

};

#endif // BACKGROUND_H
