#ifndef COIN_H
#define COIN_H

#include <entity.h>


class coin : public entity
{
    public:
        bool isCoin = true;
        int coinValue = 1;
        int counter = 0;
        int counter2 = 0;
        int lifetime = 250;

        coin();
        void updateMovement();
};

#endif // COIN_H
