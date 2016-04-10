#include "Grass.h"

Grass::Grass(int x, int y) : Object(x, y, 32, 32, SDL_LoadBMP("./trawa.bmp")) {}

Grass::~Grass()
{
}

