#pragma once
#include "Object.h"
class Board;
class Player : public Object
{
public:
	Board * board;
	Player(int x, int y);
	~Player();
	void Move(int xChange, int yChange);
	bool Colision(int x, int y);
private:
};


