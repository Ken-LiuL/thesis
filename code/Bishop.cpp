#include "Bishop.h"
#include <iostream>

Bishop::Bishop(char c,int * p)
	:Piece::Piece('B',300,c,p)	
	{}

bool Bishop::makeMove(int * toPosition,Board * b){

	return 1;	
}

int ** Bishop::legalMoves(){
	
	return NULL;

}


