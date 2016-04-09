#include "Rock.h"

Rock::Rock(int x, int y) : Object(x,y,32,32,SDL_LoadBMP("./kamien.bmp")) {}

Rock::~Rock()
{
}


