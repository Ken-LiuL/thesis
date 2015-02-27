#include "Knight.h"
#include <iostream>

Knight::Knight(char c,int * p)
	:Piece::Piece('N',300,c,p)	
	{}

bool Knight::makeMove(int * toPosition,Board * b){

	return 1;	
}


int ** Knight::legalMoves(){
	
	return NULL;

}



