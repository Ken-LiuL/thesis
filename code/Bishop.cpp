#include "Bishop.h"
#include <iostream>
using namespace std;

Bishop::Bishop(char c,int * p)
	:Piece::Piece('B',300,c,p)	
	{}

bool Bishop::makeMove(const int * toPosition,Board &b){

	return 1;	
}

vector<int*> Bishop::legalMoves(const Board &board){
	
	return vector<int*>();

}


