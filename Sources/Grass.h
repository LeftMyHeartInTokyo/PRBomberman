#ifndef GRASS_H
#define GRASS_H

class Board;
class Object;
#include "Object.h"



class Grass: public Object
{
public:
	Grass(int x, int y, Board* board);
	~Grass();
private:
	static const int resIndex = ResourceMenager::resIndexes::TRAWA;
};

#endif //GRASS_H