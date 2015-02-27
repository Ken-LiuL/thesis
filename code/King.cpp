#include "King.h"
#include <iostream>

King::King(char c,int * p)
	:Piece::Piece('K',2000,c,p)	
	{}

bool King::makeMove(int * toPosition,Board * b){

	return 1;	
}


int ** King::legalMoves(){
	
	return NULL;

}

