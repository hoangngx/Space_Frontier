#include "map.h"

background::background()
{
    sprite.setPosition(1,-635);
}

void background::updateMovement(double &speed)
{
    sprite.move(0, speed);
}
