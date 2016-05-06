#ifndef BOARD_H
#define BOARD_H

class Player;

#include <vector>
#include "Grass.h"
#include "Indestruct.h"
#include "Rock.h"
#include "Bomb.h"
#include "Object.h"

using namespace std;

class Board //kontener na elementy planszy, rysowanie jej
{
public:
	char* nameOfBoardFile; //plik, z którego wczytujemy planszê
	Player * player; //wskaŸnik na gracza
	SDL_Surface *screen; //ekran
	vector <Rock> vectorOfRocks; //zwyk³e ceg³y
	vector <Grass> vectorOfGrass; //trawa
	vector <Bomb> vectorOfBombs; //bomby
	vector <Indestruct> vectorOfIndestruct; //niezniszalne ceg³y
	Object **objects;
	Board(SDL_Surface *screen, Player * player);
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
	void DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, int x, int y);
};

#endif // BOARD_H