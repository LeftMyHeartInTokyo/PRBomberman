#pragma once
#include "Object.h"
//nie mo�e by� zniszczona przez bomb�
class Indestruct :
	public Object
{
public:
	Indestruct(int x, int y);
	~Indestruct();
};

