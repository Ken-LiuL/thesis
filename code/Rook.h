#pragma once
#include "piece.h"
class Board;
class Rook:public Piece{
 	public:
		Rook(char color, int * position);
	        bool makeMove(int * toPosition,Board * b);
	        int ** legalMoves();
};
