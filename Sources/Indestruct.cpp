#include "Indestruct.h"
Indestruct::Indestruct(int x, int y, Board* board) : Object(x, y, Object::spriteH, Object::spriteH, board, ResourceMenager::images[this->resIndex] ) {}

Indestruct::~Indestruct()
{
}

bool Indestruct::die()
{
				  // Can U die?
	return false; // http://memesvault.com/wp-content/uploads/No-Meme-02.jpg

	//https://www.youtube.com/watch?v=Hj2vU2nr5Jw
	//MWWWWAHAHAHHHAHAHHAHAHAHHAA <evliLaugh>
}