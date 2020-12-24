#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "App.h"
#include "Rect.h"
#include "Invader.h"
#include "Ship.h"
#include <deque>
#include <vector>

using namespace std;

App::App(int argc, char** argv, int width, int height, const char* title) : GlutApp(argc, argv, width, height, title) {
    spaceShip = new Ship("Ship.png", -0.175, -0.6, .15, .075);
    Invaders = new Invader("invader.png", -0.3, 0.8, .5, .25);
}

void renderText(
    string text,
    float x,
    float y,
    void* font = GLUT_BITMAP_HELVETICA_18,
    float r = 1,
    float g = 1,
    float b = 1)
{
    glColor3f(r, g, b);
    float offset = 0;
    for (int i = 0; i < text.length(); i++)
    {
        glRasterPos2f(x + offset, y);
        glutBitmapCharacter(font, text[i]);
        int w = glutBitmapWidth(font, text[i]);
        offset += ((float)w / 640) * 2;
    }
}

void App::draw() const{
    string healthStatus = to_string(Invaders->getHealth());

    if (healthStatus != "0"){
        Invaders->draw();
    }
    
    if (!gg) {
        spaceShip->draw();
    }

    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i]->draw();
    }

    if (healthStatus == "0") {
        renderText("YOU WIN! :)", -0.32, 0.85, GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1);
    }

    if (gg) {
        renderText("GAME OVER :(", -0.32, 0.85, GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1);
    }
   
    renderText("Invader Health: " + healthStatus, .3, 0.85, GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1);


}

void App::idle() {
    if (wall) {
        x = Invaders->getX();
        Invaders->setX(x -= .0001);
    }
    else{
        x = Invaders->getX();
        Invaders->setX(x += .0001);
    }

    if (Invaders->getX() <= -1){
        wall = false;
    }

    if (Invaders->getX() >= 1 - Invaders->getW()){
        wall = true;
    }

    for (int i = 0; i < bullets.size(); i++) {
        y = bullets[i]->getY();
        bullets[i]->setY(y += 0.001); //controls speed of how fast bullet fires

        if ((bullets[i]->getX() >= Invaders->getX()) &&
            (bullets[i]->getX() < Invaders->getX() + Invaders->getW()) &&
            (bullets[i]->getY() < Invaders->getY()) &&
            (bullets[i]->getY() > Invaders->getY() - Invaders->getH())) {
                bullets.erase(bullets.begin() + i);
                Invaders->decrementHealth();
        }
    }
    redraw();
}

void App::keyDown(unsigned char key, float x, float y) {
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case 'w':
        spaceShip->up();
        if (spaceShip->getY() >= 1 - spaceShip->getH()){
            redraw();
        }
        break;
    case 'a':
        spaceShip->left();
        redraw();
        break;
    case 's':
        spaceShip->down();
        redraw();
        break;
    case 'd':
        spaceShip->right();
        redraw();
        break;
    case 32:
        bullets.push_front(new Rect(spaceShip->getX() + 0.07, spaceShip->getY(), .01, .05, 0, 0, 1));
        break;
    }
}

App::~App() {
    for (auto i = bullets.begin(); i != bullets.end(); i++) {
        delete* i;
    }
    delete  spaceShip, Invaders;
    std::cout << "Exiting..." << std::endl;
}

