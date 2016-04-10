#pragma once
#include<vector>
#include "Object.h"
#include "Grass.h"
#include "Indestruct.h"
#include "Rock.h"
#include "Bomb.h"

using namespace std;
class Player;
class Board //kontener na elementy planszy, rysowanie jej
{
public:
	char * nameOfBoardFile; //plik, z którego wczytujemy planszê
	Player * player; //wskaŸnik na gracza
	SDL_Surface *screen; //ekran
	vector <Rock> vectorOfRocks; //zwyk³e ceg³y
	vector <Grass> vectorOfGrass; //trawa
	vector <Bomb> vectorOfBombs; //bomby
	vector <Indestruct> vectorOfIndestruct; //niezniszalne ceg³y
	Board(char * nameOfFile, SDL_Surface *screen, Player * player);
	Board();
	~Board();
	void AddRock(Rock obj); //dodawanie do wektora
	void AddIndestruct(Indestruct obj);
	void AddGrass(Grass obj);
	void AddBomb(Bomb bomb);
	void LoadBoardFromFile(); //wczytanie planszy z pliku
	void DrawBoard(); //rysowanie plansz
	void HandleExplosions();
	void DeleteExplodedBombs();
	void Play();

private:
	void DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, int x, int y);
};

