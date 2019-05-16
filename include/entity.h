#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <string>
#ifndef ENTITY_H
#define ENTITY_H

class entity
{
    public:
        sf::RectangleShape rect;
        sf::Sprite sprite;
        sf::Text text;
};

#endif // ENTITY_H
