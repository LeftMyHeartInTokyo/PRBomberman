#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

class Object;
class Board;

class Player : public Object
{
public:
	Player(int x, int y, Board* board);
	~Player();
	void Move(int xChange, int yChange);
	bool Colision(int x, int y);
	void PlantBomb();
	bool die();
	bool isAlive();

private:
	static const int resIndex = ResourceMenager::resIndexes::GRACZ;
	bool lives;
};


#endif // PLAYER_H