#pragma once
#include "Object.h"
class Bomb :
	public Object
{
public:
	int timeToDelete;
	int timeOfExplosion;
	Bomb(int x, int y);
	~Bomb();
	void whenToExplodeAndDelete();
	void Explode();

};

