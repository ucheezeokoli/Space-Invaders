#ifndef INVADER_H
#define INVADER_H

#include "TexRect.h"
#include "GameObj.h"

class Invader : public GameObj{
protected:
    int health;

public:
    Invader(const char*, float, float, float, float);
};

#endif




