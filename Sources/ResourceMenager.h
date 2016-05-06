#ifndef RESOURCE_MENAGER_H
#define RESOURCE_MENAGER_H

#include <vector>
#include <string>
#include "../sdl/include/SDL.h"

using std::vector;
using std::string;

class ResourceMenager
{
public:
	ResourceMenager();
	~ResourceMenager();

	enum resIndexes
	{
		KAMIEN,
		NIEZNISZCZ,
		TRAWA,
		BOMB,
		EXPLOSION_CENTER,
		EXPLOSION,
		EXPLOSION_VERTICAL,
		GRACZ,
		EKRAN_SMIERCI
	};

	static vector<SDL_Surface*> images;


private:
	static const char* imagesPaths[];
};

#endif //RESOURCE_MENAGER_H