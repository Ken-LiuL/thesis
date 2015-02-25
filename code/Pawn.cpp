#include "Pawn.h"
#include <iostream>

Pawn::Pawn(char c,int * p)
	:Piece::Piece('P',100,c,p)	
	{}

bool Pawn::moveIsLegal(int * toPosition){

	return 1;	
}

void Pawn::makeMove(int * toPosition){
	if(Pawn::moveIsLegal(toPosition)){
		;
	}
	else{
		;
	}
}

int ** Pawn::legalMoves(){
	
	return NULL;

}


