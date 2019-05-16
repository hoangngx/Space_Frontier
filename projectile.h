#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
using namespace std;
#include <entity.h>

class projectile : public entity
{
    public:
        int projectileSpeed = 10;
        int attackDamage = 1;
        int direction = 0; // 1 left - 2 right - 3 up - 4 down
        int counterLifetime = 0;
        int Lifetime = 34; // for power up purposes

        bool destroy = false;

        projectile();
        void doubleFire();
        void update();
};

#endif // PROJECTILE_H
