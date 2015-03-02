#include "King.h"
#include <iostream>
using namespace std;

King::King(char c,int * p)
	:Piece::Piece('K',2000,c,p)	
	{}

bool King::makeMove(const int * toPosition,Board &b){

	return 1;	
}


vector<int*> King::legalMoves(const Board &board){
	
	return vector<int*>();

}

