#include "King.h"
#include <iostream>

King::King(char c,int * p)
	:Piece::Piece('K',2000,c,p)	
	{}

bool King::moveIsLegal(int * toPosition){

	return 1;	
}

void King::makeMove(int * toPosition){
	if(King::moveIsLegal(toPosition)){
		;
	}
	else{
		;
	}
}

int ** King::legalMoves(){
	
	return NULL;

}

