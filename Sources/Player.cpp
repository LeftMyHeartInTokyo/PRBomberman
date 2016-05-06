#include "Player.h"
#include "Board.h"
#include "Bomb.h"

Player::Player(int x, int y, Board* board) : Object(x, y, Object::spriteH, 24, board, ResourceMenager::images[this->resIndex])
{
	this->lives = true;
}

Player::~Player(){}

bool Player::Colision(int x, int y)
{
	for (unsigned int i = 0; i < board->vectorOfRocks.size(); i++) //kolizja ze zwyk³ymi ceg³ami
	{
		if (x == board->vectorOfRocks.at(i).x && y == board->vectorOfRocks.at(i).y)
			return true;
	}

	for (unsigned int i = 0; i < board->vectorOfIndestruct.size(); i++) //kolizja z niezniszczalnymi ceg³ami
	{
		if (x == board->vectorOfIndestruct.at(i).x  && y == board->vectorOfIndestruct.at(i).y)
			return true;
	} 
	return false;
}
void Player::Move(int xChange, int yChange)
{
	if (!Colision(this->x + xChange, this->y + yChange))//jeœli nie nast¹pi³aby kolizja, zmieñ wspó³rzêdne
	{
		this->x += xChange;
		this->y += yChange;
	}
}
void Player::PlantBomb() //podsadzenie bomby
{
	Bomb bomb(this->x, this->y, this->board);
	this->board->AddBomb(bomb); //dodanie do wektora bomb na planszy
}

bool Player::die()
{
	this->lives = false;
	return true;
}

bool Player::isAlive()
{
	return this->lives;
}