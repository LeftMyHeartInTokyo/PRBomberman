#include "Object.h"
const int Object::spriteW = 32, Object::spriteH = 32;

Object::Object(int x, int y, int width, int height, Board* board, SDL_Surface * surface)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->surface = surface;
	this->board = board;
}

Object::Object(){}
Object::~Object(){}
bool Object::die(){ return true; }
