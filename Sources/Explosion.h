#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Object.h"
class Board;

class Area
{
public:
	int top, bottom, left, right;

	Area(){}
	void setBorders( int top, int bottom, int left, int right )
	{
		this->top = top;		this->bottom = bottom;
		this->left = left;		this->right = right;
	}
};

class Explosion : Object
{
public:
	Explosion(){}
	Explosion( int range, int centerX, int centerY, Board* board );
	void draw( SDL_Surface* screen );

private:
	static const int width = 32, height = 32;
	Board* board;
	int limitU, limitD, limitL, limitR, size;
	
};

#endif //EXPLOSION_H