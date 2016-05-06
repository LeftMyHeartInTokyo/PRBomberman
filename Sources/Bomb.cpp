#include "Bomb.h"
#include "Board.h"
#include "Player.h"
#include <ctime>

Bomb::Bomb(int x, int y, Board* board ) : Object(x, y, Object::spriteH, Object::spriteH, board, ResourceMenager::images[this->resIndex] )
{
	this->creationTime = clock();
	this->bombStatus = BombStatus::COUNTING_DOWN;
}

Bomb::~Bomb(){}

void Bomb::action()
{
	switch( this->bombStatus )
	{
	case BombStatus::COUNTING_DOWN:
		if( clock() - this->creationTime >= Bomb::timeOfLife )
			this->die();
		break;

	case BombStatus::EXPLODING: // KABOOOOOOOOOOOMM!
		if( clock() - this->creationTime <= Bomb::explosionDuration )
			this->explode();
		else
			this->vanish();
		break;
	}
}

bool Bomb::die()
{
	this->initExplosion();
	return false;				//absorb further killer's explosion
}

void Bomb::initExplosion()
{
	this->creationTime = clock();		 
	this->bombStatus = BombStatus::EXPLODING;
	explosion.Explosion::Explosion( this->range, this->x, this->y, this->board );
}

void Bomb::explode()
{
	return;

}

void Bomb::vanish()
{
	Grass grass(this->x, this->y, this->board);
	board->AddGrass(grass);
	this->board->vectorOfBombs.erase( 
		std::find(this->board->vectorOfBombs.begin(), this->board->vectorOfBombs.end(), *this) );
}

void Bomb::draw( SDL_Surface* screen )
{
	switch (this->bombStatus)
	{
	case BombStatus::COUNTING_DOWN:
		board->DrawSurface(screen, ResourceMenager::images[ResourceMenager::resIndexes::BOMB], this->x, this->y);
		break;

	case BombStatus::EXPLODING:
		this->explosion.draw( screen );
		//board->DrawSurface(screen, ResourceMenager::images[ResourceMenager::resIndexes::EXPLOSION_CENTER], this->x, this->y);
		break;
	}
	
}