#ifndef OBJECT_H
#define OBJECT_H


#include"../sdl/include/SDL.h"
#include "ResourceMenager.h"

class Board;

class Object
{
public:
	Object(int x, int y, int width, int height, Board* board, SDL_Surface *surface);
	Object(); //deklaracja konstruktora
	virtual ~Object(); //deklaracja destrukotra

	//informacja zwrotna: czy obiekt przepuszcza(1) czy pochlania(0) czynnik chcacy go zabic
	virtual bool die();  // powinno byc ladniej zrobione, ale ze zabijac moga tylko bomby i mechanika jest na odwal...

	SDL_Surface *surface;
	int x, y;
	int width;
	int height;
	Board* board;

	bool operator== (Object b)
	{
		if(this->x == b.x && this->y == b.y )
			return true;
		else return false;
	}

protected:
	static const int spriteW, spriteH;
	
};

#endif // OBJECT_H