#ifndef SHIP_H
#define SHIP_H

#include "TexRect.h"
#include "GameObj.h"

class Ship : public GameObj
{
public:
    Ship(const char*, float, float, float, float);
};

#endif
