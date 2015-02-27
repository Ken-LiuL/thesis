#include "Queen.h"
#include <iostream>

Queen::Queen(char c,int * p)
	:Piece::Piece('Q',900,c,p)	
	{}

bool Queen::makeMove(int * toPosition,Board * b){

	return 1;	
}


int ** Queen::legalMoves(){
	
	return NULL;

}


