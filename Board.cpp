#include "Board.h"
#include "Player.h"
#include<iostream>
#include<string>
#include<ctime>

#define OBJECTSINLINE 20 //iloœæ obiektów planszy w 1 linii
#define WIDTH 32
#define HEIGHT 32

using namespace std;


Board::Board(char *nameOfFile, SDL_Surface *screen, Player * player)
{
	this->nameOfBoardFile = nameOfFile;
	this->screen = screen;
	LoadBoardFromFile(); //za³adowanie planszy
	this->player = player;
	player->board = this;//wskaŸnik do planszy dla gracza
}

Board::~Board()
{
}

void Board::AddRock(Rock rock)
{
	this->vectorOfRocks.push_back(rock);
}
void Board::AddBomb(Bomb bomb)
{
	this->vectorOfBombs.push_back(bomb);
}
void Board::AddGrass(Grass grass)
{
	this->vectorOfGrass.push_back(grass);
}
void Board::AddIndestruct(Indestruct indes)
{
	this->vectorOfIndestruct.push_back(indes);
}
void Board::LoadBoardFromFile()
{
	char line[22];//+1 <- na koniec ³ancucha znaków '\0'
	int currentLine = 0;
	FILE *fp;
	fp = fopen(this->nameOfBoardFile, "r");
	if (fp == NULL)
		perror("Blad, nie ma pliku");
	else
	{
		while (fgets(line, 22, fp) != NULL) // 20 + 2 miejsca na \O \n...
		{
			strtok(line, "\n");
			for (int i = 0; i < OBJECTSINLINE; i++)
			{
				if (line[i] == 'X') // zwyk³a ceg³a
				{
					Rock newRock(WIDTH / 2 + i * WIDTH, HEIGHT / 2 + currentLine * HEIGHT);
					AddRock(newRock);
				}
				else if (line[i] == 'O') //trawa
				{
					Grass newGrass(WIDTH / 2 + i * WIDTH, HEIGHT / 2 + currentLine * HEIGHT);
					AddGrass(newGrass);
				}
				else if (line[i] == 'N') //niezniszczalna cegla
				{
					Indestruct newIndestruct(WIDTH / 2 + i * WIDTH, HEIGHT / 2 + currentLine * HEIGHT);
					AddIndestruct(newIndestruct);
				}
			}
			currentLine++;
		}
		fclose(fp);
	}
}
//rysowanie sprita
void Board::DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, int x, int y) {
	SDL_Rect dest;
	dest.x = x - sprite->w / 2;
	dest.y = y - sprite->h / 2;
	dest.w = sprite->w;
	dest.h = sprite->h;
	SDL_BlitSurface(sprite, NULL, screen, &dest);
};
//wykryj, czy bomby maja wybuchnac w tym momencie
void Board::HandleExplosions()
{
	for (int i = 0; i < vectorOfBombs.size(); i++)
	{
		if (vectorOfBombs.at(i).timeOfExplosion < clock())
			vectorOfBombs.at(i).Explode(); //efekt eksplozji
	}

}
//sprawdŸ, czy w tym momencie maj¹ znikn¹æ jakieœ bomby
void Board::DeleteExplodedBombs()
{
	for (int i = 0; i < vectorOfBombs.size(); i++)
	{
		if (vectorOfBombs.at(i).timeToDelete < clock())
			vectorOfBombs.erase(vectorOfBombs.begin() + i);
	}
}
//Rozegranie tury, tu wszystko sie wykonuje ostatecznie
void Board::Play()
{
	HandleExplosions();
	DrawBoard();
	DeleteExplodedBombs();
}
void Board::DrawBoard()
{
	//rysowanie elementów planysz	
	for (int i = 0; i < vectorOfRocks.size(); i++)
		DrawSurface(screen, vectorOfRocks.at(i).surface, vectorOfRocks.at(i).x, vectorOfRocks.at(i).y);
	for (int i = 0; i < vectorOfGrass.size(); i++)
		DrawSurface(screen, vectorOfGrass.at(i).surface, vectorOfGrass.at(i).x, vectorOfGrass.at(i).y);
	for (int i = 0; i < vectorOfIndestruct.size(); i++)
		DrawSurface(screen, vectorOfIndestruct.at(i).surface, vectorOfIndestruct.at(i).x, vectorOfIndestruct.at(i).y);
	for (int i = 0; i < vectorOfBombs.size(); i++)
		DrawSurface(screen, vectorOfBombs.at(i).surface, vectorOfBombs.at(i).x, vectorOfBombs.at(i).y);
	//rysowanie gracza
	DrawSurface(screen, player->surface, player->x, player->y);
}
