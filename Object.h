#pragma once
#ifndef Object_h
	#define Object_h
#include"./sdl/include/SDL.h"

class Object
{
public:
	Object(); //deklaracja konstruktora
	virtual ~Object(); //deklaracja destrukotra
	SDL_Surface *surface;
	int x, y;
	int width;
	int height;
	Object* pointerToObject;
	Object::Object(int x, int y, int width, int height, SDL_Surface *surface);
	virtual void Action() {};
};
#endif
