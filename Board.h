#pragma once
#include<vector>
#include "Object.h"
#include "Grass.h"
#include "Indestruct.h"
#include "Rock.h"

using namespace std;
class Player;
class Board //kontener na elementy planszy, rysowanie jej
{
public:
	char * nameOfBoardFile; //plik, z kt�rego wczytujemy plansz�
	Player * player; //wska�nik na gracza
	SDL_Surface *screen; //ekran
	vector <Rock> vectorOfRocks; //zwyk�e ceg�y
	vector <Grass> vectorOfGrass; //trawa
	vector <Indestruct> vectorOfIndestruct; //niezniszalne ceg�y
	Board(char * nameOfFile, SDL_Surface *screen, Player * player);
	Board();
	~Board();
	void AddRock(Rock obj); //dodawanie do wektora
	void AddIndestruct(Indestruct obj);
	void AddGrass(Grass obj);
	void LoadBoardFromFile(); //wczytanie planszy z pliku
	void DrawBoard(); //rysowanie plansz


private:
	void DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, int x, int y);
};

