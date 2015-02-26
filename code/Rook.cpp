#include "Rook.h"
#include <iostream>


Rook::Rook(char c,int * p)
	:Piece::Piece('R',500,c,p)	
	{}

bool Rook::moveIsLegal(int * toPosition){

	return 1;	
}

int ** Rook::legalMoves(){
	
	return NULL;

}



