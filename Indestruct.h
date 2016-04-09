#pragma once
#include "Object.h"
//nie mo¿e byæ zniszczona przez bombê
class Indestruct :
	public Object
{
public:
	Indestruct(int x, int y);
	~Indestruct();
};

