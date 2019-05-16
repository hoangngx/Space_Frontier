#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <entity.h>


class enemy : public entity
{
    public:
        double enemySpeed = 2.5;
        int counterWalking = 0;
        int attackDamage = 2;
        int direction = 0;
        int hp = 3;
        bool alive = true;

        enemy();
        void update();
        void updateMovement();
};

#endif // ENEMY_H
