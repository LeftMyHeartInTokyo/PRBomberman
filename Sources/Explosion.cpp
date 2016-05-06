#include "Explosion.h"
#include "Player.h"
#include "Board.h"

Explosion::Explosion( int size, int centerX, int centerY, Board* board )
{
	this->board = board;
	this->x = centerX;
	this->y = centerY;
	this->size = size;
	
	this->limitD = this->limitL = 
	this->limitR = 	this->limitU = this->size;

	Object* map[20][20];
	int thisX = centerX, thisY = centerY;
	bool canGoBottom  = true,
		 canGoTop     = true,
		 canGoLeft    = true,
		 canGoRight   = true;

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			map[i][j] = NULL;

	for(unsigned int i = 0; i < board->vectorOfRocks.size(); i++)
		map[board->vectorOfRocks.at(i).y][board->vectorOfRocks.at(i).x] = &board->vectorOfRocks.at(i);

	for(unsigned int i = 0; i < board->vectorOfIndestruct.size(); i++)
		map[board->vectorOfIndestruct.at(i).y][board->vectorOfIndestruct.at(i).x] = &board->vectorOfIndestruct.at(i);

	//add player
	map[board->player->y][board->player->x] = this->board->player;	

	//don't kill yrself
	map[thisY][thisX] = NULL;	

	//kill top
	for (int i = 0; i >= -this->size && thisY+i>=0 && canGoTop; i--)
	{
		if( map[thisY+i][thisX] != NULL )
		{
			canGoTop = map[thisY+i][thisX]->die();
			map[thisY+i][thisX] = NULL;
			
			this->limitU = -i;
			for (unsigned int i = 0; i < board->vectorOfRocks.size(); i++)//odnawianie tablicy, bo sie psulo bo usuwanie obiektu
				map[board->vectorOfRocks.at(i).y][board->vectorOfRocks.at(i).x] = &board->vectorOfRocks.at(i);
		}
	}

	//kill bottom
	for (int i = 0; i <= this->size && thisY+i < 20 && canGoBottom; i++)
	{
		if( map[thisY+i][thisX] != NULL )
		{
			canGoBottom = map[thisY+i][thisX]->die();
			map[thisY+i][thisX] = NULL;
			this->limitD = i;
			for (unsigned int i = 0; i < board->vectorOfRocks.size(); i++)
				map[board->vectorOfRocks.at(i).y][board->vectorOfRocks.at(i).x] = &board->vectorOfRocks.at(i);
		}
	}

	//kill left
	for (int i = 0; i >= -this->size && thisX+i>=0 && canGoLeft; i--)
	{
		if( map[thisY][thisX+i] != NULL )
		{
			canGoLeft = map[thisY][thisX+i]->die();
			map[thisY][thisX+i] = NULL;
			this->limitL = -i;
			for (unsigned int i = 0; i < board->vectorOfRocks.size(); i++)
				map[board->vectorOfRocks.at(i).y][board->vectorOfRocks.at(i).x] = &board->vectorOfRocks.at(i);
		}
	}

	//kill right
	for (int i = 0; i <= this->size && thisX+i < 20 && canGoRight; i++)
	{
		if( map[thisY][thisX+i] != NULL )
		{
			canGoRight = map[thisY][thisX+i]->die();
			map[thisY][thisX+i] = NULL;
			this->limitR = i;
			for (unsigned int i = 0; i < board->vectorOfRocks.size(); i++)
				map[board->vectorOfRocks.at(i).y][board->vectorOfRocks.at(i).x] = &board->vectorOfRocks.at(i);
		}
	}
}

void Explosion::draw( SDL_Surface* screen )
{
	for (int i = 1; i < this->limitU; i++)
		this->board->DrawSurface( screen , ResourceMenager::images[ ResourceMenager::resIndexes::EXPLOSION_VERTICAL ], this->x, this->y-i);

	for (int i = 1; i < this->limitD; i++)
		this->board->DrawSurface( screen , ResourceMenager::images[ ResourceMenager::resIndexes::EXPLOSION_VERTICAL ], this->x, this->y+i);

	for (int i = 1; i < this->limitL; i++)
		this->board->DrawSurface( screen , ResourceMenager::images[ ResourceMenager::resIndexes::EXPLOSION ], this->x-i, this->y);

	for (int i = 1; i < this->limitR; i++)
		this->board->DrawSurface( screen , ResourceMenager::images[ ResourceMenager::resIndexes::EXPLOSION ], this->x+i, this->y);

	this->board->DrawSurface( screen , ResourceMenager::images[ ResourceMenager::resIndexes::EXPLOSION_CENTER ], this->x, this->y);
}

