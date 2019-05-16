#ifndef RENDERBLACKHOLE_H
#define RENDERBLACKHOLE_H

#include <renderInfo.h>


class renderBlackHole : public renderInfo
{
    public:
        renderBlackHole();
        void isReady();
        void isNotReady();
};

#endif // RENDERBLACKHOLE_H
