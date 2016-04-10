#include "Player.h"
#include "Board.h"
#include "Bomb.h"

Player::Player(int x, int y) : Object(x, y, 32, 24, SDL_LoadBMP("./gracz.bmp")) {}

Player::~Player()
{
}

bool Player::Colision(int x, int y)
{
	for (int i = 0; i < board->vectorOfRocks.size(); i++) //kolizja ze zwyk³ymi ceg³ami
	{
		if (x > board->vectorOfRocks.at(i).x - board->vectorOfRocks.at(i).width
			&& x < board->vectorOfRocks.at(i).x + board->vectorOfRocks.at(i).width
			&& y > board->vectorOfRocks.at(i).y - board->vectorOfRocks.at(i).height
			&& y < board->vectorOfRocks.at(i).y + board->vectorOfRocks.at(i).height)
			return true;
	}

	for (int i = 0; i < board->vectorOfIndestruct.size(); i++) //kolizja z niezniszczalnymi ceg³ami
	{
		if (x > board->vectorOfIndestruct.at(i).x - board->vectorOfIndestruct.at(i).width
			&& x < board->vectorOfIndestruct.at(i).x + board->vectorOfIndestruct.at(i).width
			&& y > board->vectorOfIndestruct.at(i).y - board->vectorOfIndestruct.at(i).height
			&& y < board->vectorOfIndestruct.at(i).y + board->vectorOfIndestruct.at(i).height)
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
	Bomb bomb(this->x, this->y);
	bomb.whenToExplodeAndDelete(); //ustwienie momentu wybuchu i znikniecia
	this->board->AddBomb(bomb); //dodanie do wektora bomb na planszy
}
