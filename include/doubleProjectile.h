#ifndef DOUBLEPROJECTILE_H
#define DOUBLEPROJECTILE_H

#include <renderInfo.h>


class doubleProjectile : public renderInfo
{
    public:
        int DoubleProjectilePrice = 15;

        doubleProjectile();
        void isReady();
        void update(int &Spaceship1$, int &projectileDamage);
        void isNotReady();
};

#endif // DOUBLEPROJECTILE_H
