#ifndef MEDKIT_H
#define MEDKIT_H

#include <renderInfo.h>

class medkit : public renderInfo
{
    public:
        medkit();
        int medkitPrice = 10;
        int counter = 0;

    void update(int &Spaceship1$,int &spaceShipHp);
    void isReady();
    void isNotReady();
};

#endif // MEDKIT_H
