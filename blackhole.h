#ifndef BLACKHOLE_H
#define BLACKHOLE_H

#include <entity.h>


class blackhole : public entity
{
    public:
        int BlackHoleCost = 20;

        blackhole();
        void update();
        void updateCoin(int &spaceship$);

        bool destroy = false;
};

#endif // BLACKHOLE_H
