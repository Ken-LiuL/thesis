#include "Bishop.h"
#include <iostream>

Bishop::Bishop(char c,int * p)
	:Piece::Piece('B',300,c,p)	
	{}

bool Bishop::moveIsLegal(int * toPosition){

	return 1;	
}

void Bishop::makeMove(int * toPosition){
	if(Bishop::moveIsLegal(toPosition)){
		;
	}
	else{
		;
	}
}

int ** Bishop::legalMoves(){
	
	return NULL;

}


