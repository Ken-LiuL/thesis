#include "Knight.h"
#include <iostream>
using namespace std;

Knight::Knight(char c,int * p)
	:Piece::Piece('N',300,c,p)	
	{}

bool Knight::makeMove(const int * toPosition, Board &b){

	return 1;	
}


vector<int*> Knight::legalMoves(const Board &board){
	
	return vector<int*>();

}



