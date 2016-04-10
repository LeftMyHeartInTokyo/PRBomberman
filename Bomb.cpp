#include "Bomb.h"
#include <ctime>

Bomb::Bomb(int x, int y) : Object(x, y, 32, 32, SDL_LoadBMP("./bomba.bmp")) {} 

Bomb::~Bomb()
{
}

void Bomb::whenToExplodeAndDelete() //kiedy ma nastapic wybuch i kiedy bomba ma zniknac
{
	this->timeOfExplosion = clock() + 3 * CLOCKS_PER_SEC;
	this->timeToDelete = clock() + 4 * CLOCKS_PER_SEC;
}

void Bomb::Explode()//moment eksplozji
{
	this->surface = SDL_LoadBMP("./wybuch.bmp");//obrazek wybuchu
}