#include "Rook.h"
#include <iostream>

Rook::Rook(char c,int * p)
	:Piece::Piece(500,c,p)	
	{}

bool Rook::moveIsLegal(int * toPosition){

	return 1;	
}

void Rook::makeMove(int * toPosition){
	if(Rook::moveIsLegal(toPosition)){
		;
	}
	else{
		;
	}
}

int ** Rook::legalMoves(){
	
	return NULL;

}


//module test
int main(){
	int *positionOne = new int[2];
	positionOne[0] = 1;
	positionOne[1] = 2;
	Rook pOne = Rook('W',positionOne);
	int *positionTwo = new int[2];
	positionTwo[0] = 3;
	positionTwo[1] = 5;
	Rook pTwo = Rook('B',positionTwo);
	using namespace std;
	cout << pOne.getValue() << " " << pOne.getColor() << endl;
	cout << pTwo.getValue() << " " << pTwo.getColor() << endl;
	delete positionOne;
	delete positionTwo;
}

