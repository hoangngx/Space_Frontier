#ifndef SPEEDUP_H
#define SPEEDUP_H

#include <renderInfo.h>


class speedUp : public renderInfo
{
    public:
        int speedUpcost = 15;

        speedUp();
        void update(int &spaceShip$, int &projectileSpeed, int &projectileRange);
        void isReady();
};

#endif // SPEEDUP_H
