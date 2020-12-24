#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "Rect.h"
#include "Invader.h"
#include "Ship.h"
#include "TexRect.h"
#include "GameObj.h"
#include <deque>

using namespace std;


class App : public GlutApp {

    GameObj* spaceShip;
    GameObj* Invaders;
    deque<Rect*> bullets;

    float y,x;
    bool gg = false;
    bool wall = true;
public:

    App(int argc, char** argv, int width, int height, const char* title);

    void draw() const;

    void keyDown(unsigned char key, float x, float y);

    void idle();

    ~App();

};

#endif
