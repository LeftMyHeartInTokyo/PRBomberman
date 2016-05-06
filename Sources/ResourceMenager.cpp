#include "ResourceMenager.h"

vector<SDL_Surface*> ResourceMenager::images;
const char* ResourceMenager::imagesPaths[] = {  "./Resources/kamien.bmp",
												"./Resources/niezniszcz.bmp",
												"./Resources/trawa.bmp",
												"./Resources/bomb.bmp",
												"./Resources/explosion_central.bmp",
												"./Resources/explosion.bmp",
												"./Resources/explosionVertical.bmp",
												"./Resources/gracz.bmp",
												"./Resources/deathScreen.bmp",
												'\0' };	//paths to img sources - must be null-terminated

ResourceMenager::ResourceMenager()
{
	for (int i = 0; ResourceMenager::imagesPaths[i] != '\0' ; i++)
		this->images.push_back( SDL_LoadBMP( ResourceMenager::imagesPaths[i] ) );
}

ResourceMenager::~ResourceMenager()
{
	for (unsigned int i = 0; i < this->images.size(); i++)
		SDL_FreeSurface( this->images.at(i) );
	images.clear();
}