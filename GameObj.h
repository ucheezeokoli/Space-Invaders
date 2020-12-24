#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include "TexRect.h"

class GameObj: public TexRect {
protected: 
    int health;
public: 
    GameObj(const char*, float, float, float, float);
    int getHealth();
    void decrementHealth();
};

#endif