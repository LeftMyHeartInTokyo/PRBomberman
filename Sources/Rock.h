#ifndef ROCK_H
#define ROCK_H


#include "Object.h"
#include "ResourceMenager.h"

class Object;
class Board;


class Rock:public Object
{
public:
	Rock(int x, int y, Board* board);
	~Rock();
	bool die();

private:
	static const int resIndex = ResourceMenager::resIndexes::KAMIEN;
};

#endif //ROCK_H