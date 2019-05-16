#ifndef SPACESHIPHEALTH_H
#define SPACESHIPHEALTH_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
using namespace std;
#include <renderInfo.h>


class spaceShipHealth : public renderInfo
{
    public:
        int counter = 0;
        spaceShipHealth();
        void update();
        void powerUp();
};

#endif // SPACESHIPHEALTH_H
