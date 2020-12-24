#include "GameObj.h"

using namespace std;

GameObj::GameObj(const char* filename, float x, float y, float w, float h): TexRect(filename, x, y, w, h){
    health = 100;
}

int GameObj::getHealth() {
    return health;
}

void GameObj::decrementHealth() {
    if (health > 0){
        health -= 10;
    }

}