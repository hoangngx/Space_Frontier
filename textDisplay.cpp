#include "textDisplay.h"
#include "random.h"

textDisplay::textDisplay()
{
    if (generateRandomSpaceship() == 0) text.setColor(sf::Color(255, 0, 20));
    else if (generateRandomSpaceship() == 1) text.setColor(sf::Color::White);
    else if (generateRandomSpaceship() == 2) text.setColor(sf::Color(204, 204, 0));
    else if (generateRandomSpaceship() == 3) text.setColor(sf::Color(30, 144, 255));
    else if (generateRandomSpaceship() == 4) text.setColor(sf::Color(106, 90, 225));
    else if (generateRandomSpaceship() == 5) text.setColor(sf::Color(204, 204, 0));
    else if (generateRandomSpaceship() == 6) text.setColor(sf::Color(204, 204, 0));
    else if (generateRandomSpaceship() == 7) text.setColor(sf::Color(204, 204, 0));
    else if (generateRandomSpaceship() == 8) text.setColor(sf::Color(204, 204, 0));
    text.setCharacterSize(50);
    text.setString(myString);
}

void textDisplay::update()
{
    text.move(0, -movementSpeed);
    counter++;
    if (counter >= lifetime)
    {
        destroy = true;
    }
}
