#include "Indestruct.h"


Indestruct::Indestruct(int x, int y) : Object(x, y, 32, 32, SDL_LoadBMP("./niezniszcz.bmp")) {}

Indestruct::~Indestruct()
{
}
