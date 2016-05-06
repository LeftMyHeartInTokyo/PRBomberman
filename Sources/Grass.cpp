#include "Grass.h"

Grass::Grass(int x, int y, Board* board) : Object(x, y, Object::spriteH, Object::spriteH, board, ResourceMenager::images[this->resIndex] ) {}

Grass::~Grass()
{
}

