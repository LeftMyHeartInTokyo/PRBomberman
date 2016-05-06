#include "Rock.h"
#include "Board.h"

Rock::Rock(int x, int y, Board* board) : Object(x, y, Object::spriteH, Object::spriteH, board, ResourceMenager::images[this->resIndex] ) {}

Rock::~Rock()
{
}


bool Rock::die()
{	
	Grass grass(this->x, this->y, this->board);
	board->AddGrass( grass );
	this->board->vectorOfRocks.erase( 
		std::find(this->board->vectorOfRocks.begin(), this->board->vectorOfRocks.end(), *this) );

	return false;
}