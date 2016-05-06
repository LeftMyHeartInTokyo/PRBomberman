#define _CRT_SECURE_NO_WARNINGS
#include "Board.h"
#include "Player.h"
#include<iostream>
#include<string>
#include<ctime>
#include <vector>

using namespace std;


Board::Board(SDL_Surface *screen, Player * player)
{
	this->nameOfBoardFile = "./Resources/etap.txt";
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
					Rock newRock(i, currentLine, this);
					AddRock(newRock);
				}
				else if (line[i] == 'O') //trawa
				{
					Grass newGrass(i, currentLine, this);
					AddGrass(newGrass);
				}
				else if (line[i] == 'N') //niezniszczalna cegla
				{
					Indestruct newIndestruct(i, currentLine, this);
					AddIndestruct(newIndestruct);
				}
			}
			currentLine++;
		}
		fclose(fp);
	}
}


//rysowanie sprita
void Board::DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, int column, int row)
{
	SDL_Rect dest;
	dest.x = WIDTH / 2 + column * WIDTH - sprite->w / 2;
	dest.y = HEIGHT / 2 + row*HEIGHT - sprite->h / 2;
	dest.w = sprite->w;
	dest.h = sprite->h;
	SDL_BlitSurface(sprite, NULL, screen, &dest);
};

//Rozegranie tury, tu wszystko sie wykonuje ostatecznie
void Board::Play()
{
	for (unsigned int i = 0; i < vectorOfBombs.size(); i++)
		vectorOfBombs.at(i).action();

	DrawBoard();
}
void Board::DrawBoard()
{
	//rysowanie elementów planszy
	for (unsigned int i = 0; i < vectorOfRocks.size(); i++)
		DrawSurface(screen, vectorOfRocks.at(i).surface, vectorOfRocks.at(i).x, vectorOfRocks.at(i).y);

	for (unsigned int i = 0; i < vectorOfGrass.size(); i++)
		DrawSurface(screen, vectorOfGrass.at(i).surface, vectorOfGrass.at(i).x, vectorOfGrass.at(i).y);

	for (unsigned int i = 0; i < vectorOfIndestruct.size(); i++)
		DrawSurface(screen, vectorOfIndestruct.at(i).surface, vectorOfIndestruct.at(i).x, vectorOfIndestruct.at(i).y);
		
	for (unsigned int i = 0; i < vectorOfBombs.size(); i++)
		vectorOfBombs.at(i).draw(screen);

	//rysowanie gracza
	DrawSurface(screen, player->surface, player->x, player->y);
}
