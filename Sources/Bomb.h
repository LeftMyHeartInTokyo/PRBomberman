#ifndef BOMB_H
#define BOMB_H


#include "Object.h"
#include "Explosion.h"
class Board;

#define OBJECTSINLINE 20 //iloœæ obiektów planszy w 1 linii
#define WIDTH 32
#define HEIGHT 32

enum BombStatus
{
	COUNTING_DOWN,
	EXPLODING
};

class Bomb : public Object
{
public:
	Bomb(int x, int y, Board* board);
	~Bomb();

	void action();
	void draw( SDL_Surface* screen );
	//informacja zwrotna: czy obiekt przepuszcza(1) czy pochlania(0) czynnik chcacy go zabic
	bool die();

private:
	static const int resIndex = ResourceMenager::resIndexes::BOMB;
	static const int timeOfLife = 3000;
	static const int explosionDuration = 1500;
	static const int range = 3;

	int creationTime;
	BombStatus bombStatus;
	Explosion explosion;

	void initExplosion();
	void explode();
	void vanish();
};

#endif //BOMB_H