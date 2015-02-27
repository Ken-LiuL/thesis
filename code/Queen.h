#pragma once
#include "piece.h"
class Board;
class Queen:public Piece{
 	public:
		Queen(char color, int * position);
	        bool makeMove(int * toPosition,Board * b);
	        int ** legalMoves();
};
