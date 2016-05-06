#ifndef INDESTRUCT_H
#define INDESTRUCT_H

#include "Object.h"
//nie mo�e by� zniszczona przez bomb�

class Object;
class Board;

class Indestruct:public Object
{
public:
	Indestruct(int x, int y, Board* board);
	~Indestruct();
	bool die();

private:
	static const int resIndex = ResourceMenager::resIndexes::NIEZNISZCZ;
};

#endif //INDESTRUCT_H