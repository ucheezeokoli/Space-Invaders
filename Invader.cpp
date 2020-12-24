#include "Invader.h"


using namespace std;

Invader::Invader(const char* filename, float x, float y, float w, float h): GameObj(filename, x, y, w, h){
    health = 100;
}
