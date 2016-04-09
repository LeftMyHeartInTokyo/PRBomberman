#include "Object.h"
Object::Object(int x, int y, int width, int height, SDL_Surface * surface)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->surface = surface;
}


Object::~Object()
{

}
