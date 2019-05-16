#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <entity.h>


class spaceship:public entity
{
    public:
        double shipSpeed = 7;
        int attackDamage = 5;
        int direction = 0; // 1=Left | 2=Right | 3=Up | 4=Down
        int hp = 10;
        int $ = 0;

        bool alive = true;
        bool canMoveLeft = true;
        bool canMoveRight = true;
        bool canMoveDown = true;

        spaceship();
        void update();
        void updateMovement();

};

#endif // SPACESHIP_H
