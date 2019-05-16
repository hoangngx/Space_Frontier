#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <entity.h>
#include <string>

class textDisplay : public entity
{
public:
    int counter = 0;
    int lifetime = 20;
    float movementSpeed = 2;
    std::string myString = "Default";
    bool destroy = false;

    textDisplay();
    void update();
};

#endif // TEXTDISPLAY_H
