#include "Rook.h"
#include <iostream>


Rook::Rook(char c,int * p)
	:Piece::Piece('R',500,c,p)	
	{}

bool Rook::makeMove(int * toPosition,Board * b){

	return 1;	
}

int ** Rook::legalMoves(){
	
	return NULL;

}



